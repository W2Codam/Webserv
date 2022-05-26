/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:34:12 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/26 20:13:41 by pvan-dij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

ft::Request::Request(const char* Buffer)
{
    std::string item;
    std::istringstream iss(Buffer);

    std::getline(iss, item, ' ');
	setMethod(item);
    std::getline(iss, this->path, ' ');
    std::getline(iss, this->version);

	std::pair<std::string, std::string> output;
	while (std::getline(iss, item)) // TODO: Make this better
	{
    	item.erase(remove_if(item.begin(), item.end(), [](char c){return !(c>=32);}), item.end());  
		if (!item.empty())
		{
			ft::slice(item, ':', output);
			fields[output.first] = output.second;
		}
	}
}

//////////////////////////////////////////

void ft::Request::display(void) const
{
	std::cout << static_cast<int>(method) << "-";
	std::cout << path << "-";
	std::cout << version << std::endl;

	for (const auto [key, value] : fields)
		std::cout << key << ":" << value << std::endl;
}

ft::Request ft::Request::getFirst(int32_t Socket)
{
    char buffer[30000] = {0};
	ft::receive(Socket, buffer, sizeof(buffer), 0);
	return (ft::Request(buffer));
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
