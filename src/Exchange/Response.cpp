/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Response.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:34:00 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/06/15 10:05:38 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"
#include "Request.hpp"

//////////////////////////////////////////

ft::Response::Response(Request req)
{
	//this should properly construct a response based on the earlier received request
	data = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
}

//////////////////////////////////////////

/** As one giant shit strings
 * CODE - STATUS
 * <HEADER>
 * \n\n 
 * <BODY>
 * 
 * HTTP/1.1 503 Service Unavailabe\n
 * Content-Type: text/plain\n
 * Content-Length: 12\n
 * \n
 * 503 error
 */

// Writes the header object
void ft::Response::writeHeader(void)
{
	// HTTP/1.1 503 Service Unavailabe\n
	data += ft::format("HTTP/1.1 %u %s\n", status, ft::getStatusCodes().at(status).c_str());
	fields["Server"] = "Breadserv";
}

void ft::Response::writeFields(void)
{
	for (const auto [key, value] : this->fields)
		data += key + " : " + value + '\n';
}

void ft::Response::writeEnd(void)
{
	data += "\n";
}

void ft::Response::send(int32_t socket)
{
	ft::send(socket, this->data.data(), this->data.length(), 0);
}
