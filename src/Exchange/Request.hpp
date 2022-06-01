/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:13:27 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/06/01 12:12:58 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef REQUEST_HPP
# define REQUEST_HPP
# include "Exchange.hpp"
FT_BEGIN

// A Request is from the incoming client.
class Request final : public Exchange
{
public: // Ctor ~ Dtor
	Request(const char* Buffer);

public: // Methods
	void display(void) const;

private:
	void setMethod(const std::string& method);

public: // Attributes

	// The request method, GET, POST, DELETE
	ft::ExchangeMethod method;
	std::string path;
	std::string version;
};

FT_END
#endif
