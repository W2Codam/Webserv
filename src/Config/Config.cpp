/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Config.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:44:03 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/30 15:38:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

const std::string* ft::Config::getValue(std::string& key) const
{
	auto it = this->fields.find(key);

	return (it != this->fields.end() ? &it->second : nullptr);
}

bool ft::Config::keyExists(std::string& key) const
{
	return (this->fields.count(key) > 0);
}

bool ft::Config::setValue(std::string& key, std::string &value)
{
	std::__1::pair ret = this->fields.insert({key, value});
	return (ret.second);
}
