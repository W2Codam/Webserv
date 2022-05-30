/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Config.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:43:14 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/30 14:14:42 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONFIG_HPP
# define CONFIG_HPP
# include "Common.hpp"
FT_BEGIN

// A config singleton object that reads and stores the server information.
class Config
{
public: // Ctor ~ Dtor
	Config() = default;
	Config(Config &other) = delete;
	Config& operator=(const Config&) = default;

public: // Functions
	const std::string* getValue(std::string& key) const;
	bool keyExists(std::string& key) const;
	bool setValue(std::string& key, std::string& value);

public: // Attributes
private:
	std::map<std::string, std::string> fields;
};

FT_END
#endif
