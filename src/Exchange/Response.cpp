/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Response.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:34:00 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/26 17:02:39 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

//////////////////////////////////////////


//////////////////////////////////////////

// Note: Im a memory rapist
void ft::Response::send(int32_t socket, const std::vector<uint8_t>& buffer)
{
	std::vector<uint8_t> rawResponse;
	
	// Build Header //

	std::string temp;
	for (const auto [key, value] : this->fields)
	{
		temp = key + " : " + value + '\n';

		for (size_t i = 0; i < temp.length(); i++)
			rawResponse.push_back(temp[i]);		
	}
	rawResponse.push_back('\n');

	// Build data //

	rawResponse.insert(rawResponse.end(), buffer.begin(), buffer.end());
	ft::send(socket, rawResponse.data(), rawResponse.size(), 0);
}
