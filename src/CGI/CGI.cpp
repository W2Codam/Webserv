/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   CGI.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/31 16:27:42 by fbes          #+#    #+#                 */
/*   Updated: 2022/08/04 19:06:57 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "CGI.hpp"

static std::vector<const char*> c_arr(const std::vector<std::string> &v)
{
	std::vector<const char*> c_arr;

	for (const std::string &val: v)
		c_arr.push_back(val.c_str());
	c_arr.push_back(NULL);
	return (c_arr);
}

bool ft::CGI::runCGI(const ft::Connection& conn, const std::string& path, std::string& out, const std::string& cgiBin)
{
	std::vector<std::string> argv = {cgiBin, path};
	std::vector<std::string> envp;
	envp.push_back("GATEWAY_INTERFACE=CGI/1.1");
	envp.push_back("REMOTE_ADDR=" + conn.ipv4);
	envp.push_back("REQUEST_METHOD=POST");
	envp.push_back("SCRIPT_NAME=" + path);
	envp.push_back("SERVER_NAME=localhost");
	envp.push_back("SERVER_PROTOCOL=HTTP/1.1");
	envp.push_back("PATH_INFO=~/work/webserv/examples/www/post/fileupload.sh"); // TODO: Remove abs path
	envp.push_back("CONTENT_LENGTH=" + conn.request->headers["content-length"]);

	pid_t pid;
	ft::fd_t fds[2];
	try { ft::pipe(fds); pid = ft::fork();}
	catch(const std::exception& e)
	{
		close(fds[WRITE]);
		close(fds[READ]);

		std::cerr << RED << "Webserv: " << e.what() << RESET << std::endl;
		return (false);
	}
	if (pid == 0) // Child
	{
		try
		{
			ft::dup2(0, STDIN_FILENO);
			ft::dup2(fds[WRITE], STDOUT_FILENO);
			ft::dup2(fds[WRITE], STDERR_FILENO);

			ft::execve(cgiBin.c_str(), const_cast<char *const *>(c_arr(argv).data()), const_cast<char *const *>(c_arr(envp).data()));
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << BLACK << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else // Parent
	{
		wait(NULL);
	}
	return (true);
}
