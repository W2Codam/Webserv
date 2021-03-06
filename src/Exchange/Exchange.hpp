/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Exchange.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:13:27 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/06/17 09:12:08 by pvan-dij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EXCHANGE_HPP
# define EXCHANGE_HPP
# include "CommonNetwork.hpp"
# include "ServerSection.hpp"
FT_BEGIN

// Supported exchange methods for the webserver.
enum class Method : uint8_t
{
	GET,
	POST,
	DELETE,
	ERR
};

// An exchange is both a response and a request via http.
class Exchange
{
public: // Ctor ~ Dtor
	virtual ~Exchange() { }

public: // Functions
	/**
	 * @brief check if a key exists in the headers
	 *
	 * @param key the key to check for
	 * @return true if the key exists
	 */
	bool keyExists(const std::string& key) const;

	/**
	 * @brief get the value of a header field
	 *
	 * @param key the key of a header field to get the value of
	 * @return a pointer to the value (NULL if field does not exist)
	 */
	const std::string* getValue(const std::string& key) const;

public: // Attributes

	// The exchange make-up and parameters.
	std::map<std::string, std::string> fields;

	// The raw data of the exchange method, e.g: file, text, script, ...
	std::string data;

	// The either incoming or outgoing socket of the exchange.
	int32_t socket;
};

FT_END
#endif
