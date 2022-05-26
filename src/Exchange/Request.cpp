/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:34:12 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/26 09:42:02 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

ft::Request::Request(const char* Buffer)
{
    std::string item;
	std::string temp;
    std::istringstream iss(Buffer);

    std::getline(iss, item, ' ');
	setMethod(item);
    std::getline(iss, this->path, ' ');
    std::getline(iss, this->version);

	std::pair<std::string, std::string> output;
	while (std::getline(iss, item)) // TODO: Make this better
	{
		ft::slice(item, ':', output);
		fields[output.first] = output.second;
	}
}

//////////////////////////////////////////

void ft::Request::display(void) const
{
	std::cout << static_cast<uint8_t>(method) << "-";
	std::cout << path << "-";
	std::cout << version << std::endl;

	for (const auto [key, value] : fields)
		std::cout << key << ":" << value << std::endl;
}

void ft::Request::setMethod(const std::string& inMethod)
{
	if (inMethod == "GET")
		method = ft::ExchangeMethod::GET;
	else if (inMethod == "POST")
		method = ft::ExchangeMethod::POST;
	else if (inMethod == "DELETE")
		method = ft::ExchangeMethod::DELETE;
}

//////////////////////////////////////////
