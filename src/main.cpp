/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:39:03 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/06/01 16:45:27 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Server/Server.hpp"
#include "Config/GlobalConfig.hpp"

/**
 * Program entry point.
 * 
 * @param argc Argument count.
 * @param argv Argument value.
 * @return Either EXIT_SUCCESS or EXIT_FAILURE
 */
int32_t main(int32_t argc, const char* argv[])
{
	// Check arguments
	if (argc != 2)
	{
		std::cerr << "\nWebserv: Invalid arguments\n" << std::endl;
		std::cerr << "Usage: ./Webserv <Configuration Filepath>\n" << std::endl;
		return (EXIT_FAILURE);
	}

	// Handle Interrupt signals
	signal(SIGINT, [](int32_t val) 
	{
		std::cout << "Webserv: Signal catched, shutting down" << std::endl;
		exit (EXIT_FAILURE);
	});

	// Read config file ...
	ft::GlobalConfig config;
	if (!config.readFile(argv[2]))
	{
		std::cerr << "Webserv: Invalid failed to read config file." << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		while (true)
		{
			for (auto& server : config.getServers())
			{
				
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << "Webserv: Shutting down" << std::endl;
	return (EXIT_SUCCESS);

	// Bullshit below //

	/*
	ft::Config dummy;
	ft::Server server(dummy);

	server.init();
	while (true)
	{
		server.run();
	}
	*/
}

// curl --verbose http://localhost:8080/
// --header for custom headers ala "header:123"
