/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Server.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 11:08:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/07/31 14:16:50 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

ft::Server::Server(ft::ServerSection& inConfig) : config(inConfig) {}

//////////////////////////////////////////

void ft::Server::respondWithStatus(pollfd* poll, int32_t statusCode)
{
	// if (this->responses.find(poll->fd) != this->responses.end())
	// 	delete this->responses[poll->fd];

	// this->responses[poll->fd] = new ft::Response(code, &(this->config));
	// std::cout << "Pollout now" << std::endl;
	// poll->events = POLLOUT;
}

void ft::Server::setSocket(const ft::Poller::Socket* socket)
{
	this->socket = const_cast<ft::Poller::Socket*>(socket);
}

const ft::Poller::Socket* ft::Server::getSocket(void) const
{
	return (this->socket);
}

//////////////////////////////////////////

/*
void ft::Server::pollInEvent(pollfd* poll)
{
	std::cout << BLACK << "Incoming Request" << RESET << std::endl;

	ssize_t brecv;							// Bytes received
	const size_t BUFF_SIZE = 4096;			// Buffer size
	static char buffer[BUFF_SIZE] = {0};	// The buffer

	// Receive the incoming message
	if ((brecv = recv(poll->fd, buffer, BUFF_SIZE, NONE)) <= 0)
	{
		if (brecv == NONE)
			std::cerr << BLACK << "Connection closed by client" << RESET << std::endl;
		else
			std::cerr << RED << "Receive function has failed!" << RESET << std::endl;

		close(poll->fd);
		poll->fd = -1;
		return;
	}

	// Parse the incoming request
	try
	{
		// TODO: Parse HTTP request
	}
	catch (const ft::PayloadTooLarge& e)
	{
		this->respondWithStatus(poll, 413);
		return;
	}
	catch (const ft::BadRequest& e)
	{
		this->respondWithStatus(poll, 400);
		return;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << RED << "Failed to allocate memory" << RESET << std::endl;
		this->respondWithStatus(poll, 507);
		return;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Something went wrong while parsing request" << RESET << std::endl;
		this->respondWithStatus(poll, 500);
		return;
	}

	poll->events = POLLOUT;
}

void ft::Server::pollOutEvent(pollfd* poll)
{
	// TODO: Prevent timeout!
	// TODO: Use response class to send response.

	std::cout << "\033[30;1m" << "Sent Response" << "\033[0m" << std::endl;
}
*/

/*
void ft::Server::run(pollfd* fds, size_t size)
{
	// Check our open fds for events.
	ft::poll(fds, size, 0);

	for (int i = 0; i < size; i++)
	{
		pollfd* poll = &fds[i];

		// Create new connection
		if (!i && (fds[0].revents & POLLIN))
			this->pollListen();
		// Pollfd is ready for reading.
		else if (poll->revents & POLLIN)
			this->pollInEvent(poll);
		// Pollfd is ready for writing.
		else if (poll->revents & POLLOUT)
			this->pollOutEvent(poll);
	}
}
*/
