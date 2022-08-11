/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/27 11:07:36 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/08/10 14:20:01 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef REQUEST_HPP
# define REQUEST_HPP
# include <sstream>
# include "Utils.hpp"
# include "Exchange.hpp"
# include "Exceptions.hpp"
# include "ServerSection.hpp"
# include "Connection.hpp"
# include "Server.hpp"

namespace ft {

/**
 * Request
 * A Request is from the incoming client.
 *
 * GET /reference/string/to_string/ HTTP/1.1\n
 * Content-Type: text/plain\n
 * Content-Length: 12\n
 * \r\n\r\n
 * body
 */
class Request final : public ft::Exchange
{
public: // Ctor ~ Dtor
	Request(const std::vector<ft::Server>& servers) noexcept;

public: // Functions
	void appendBuffer(const std::string& buffer);
	void parseHeader(ft::Connection& conn);
	bool isHeaderDone(void) const;
	bool isHeaderParsed(void) const;
	bool isBodyDone(void) const;

private:
	void parseBody();
	void parseStatusLine(const std::string& buffer);

public: // Attributes
	ft::Exchange::Method method;
	std::string path;
	std::string version;
	bool headerParsed;

private:
	const std::vector<ft::Server>& servers;
	bool headerDone;
};

}
#endif
