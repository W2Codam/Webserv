/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:13:27 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/07/15 17:04:14 by pvan-dij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef REQUEST_HPP
# define REQUEST_HPP
# include "Exchange.hpp"
FT_BEGIN

/**
 * Request
 * A Request is from the incoming client.
 *
 * GET /reference/string/to_string/ HTTP/1.1\n
 * Content-Type: text/plain\n
 * Content-Length: 12\n
 * \n
 * bla bla bla
 */
class Request final : public Exchange
{
public: // Ctor ~ Dtor
	Request() {}
	Request(std::string buffe, std::string ipv4);

public: // Methods
	void display(void) const;
	void setMethod(const std::string& method);
	bool parse(void);

private:

public: // Attributes

	// The request method, GET, POST, DELETE
	ft::Method method;
	std::string path;
	std::string version;
	std::string body;
	std::string ipv4;
	std::string buffer;
};

FT_END
#endif
