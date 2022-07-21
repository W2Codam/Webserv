/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Request.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 19:34:12 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/07/21 16:14:43 by pvan-dij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

//all valid header field characters
// "!#$%&'*+-.^_`|~0123456789abdefghijklmnopqrstuvwxyzABCDEFGHJIKLMNOPQRSTUVWVXYZ";

void parseLineOne(ft::Request &req, std::string lineOne)
{
	std::vector<std::string> fields;

	ft::split(lineOne, " ", fields);
	if (fields.size() != 3)
		throw ft::BadRequest();

	req.setMethod(fields[0]);
	req.path = fields[1];
	req.version = fields[2];
}

bool isAscii (const std::string& s, size_t pos)
{
    return !std::any_of(s.begin(), (s.begin() + pos), [](char c) { 
        return static_cast<unsigned char>(c) > 127; 
    });
}

bool ft::Request::parse(size_t bodySize)
{
	if (this->buffer.size() < 1)
		throw ft::BadRequest();
	
	for (int i = 0; i < 3; i++)
		if (!isupper(this->buffer[i]))
			throw ft::BadRequest();

	size_t pos = this->buffer.find("\r\n\r\n");
	if (pos== std::string::npos)
		return (false);

	if (isAscii(this->buffer, pos) == false)
		throw ft::BadRequest();


	std::pair<std::string, std::string> splitBuffer(buffer.substr(0, pos), buffer.substr(pos));
	std::istringstream iss(splitBuffer.first);
	std::vector<std::string> tempFields;
	ft::trim(splitBuffer.first);
	ft::split(splitBuffer.first, "\n", tempFields);

	parseLineOne(*this, tempFields[0]);
	tempFields.erase(tempFields.begin());

	std::pair<std::string, std::string> output;
	for (std::string &val : tempFields)
	{	
		ft::trim(val);
		val.erase(remove_if(val.begin(), val.end(), [](char c){return !(c>=32);}), val.end());
		if (!val.empty())
		{
			if (val.find(':') == std::string::npos)
				throw ft::BadRequest();
			ft::slice(val, ':', output);
			ft::trim(output.second);
			if (output.second.empty())
				throw ft::BadRequest();
			this->fields[output.first] = output.second;
		}
	}	


	if (splitBuffer.second.size() > 0)
		this->body += splitBuffer.second;

	if (this->body.size() > bodySize)
		throw ft::PayloadTooLarge();

	if (this->method == ft::Method::POST)
	{
		std::cout << this->body.size() <<std::endl;
		std::cout << std::stoul(this->fields["Content-Length"]) <<std::endl;
		if (this->body.size() < std::stoul(this->fields["Content-Length"]))
		{
			std::cout << "AFEWFOJWFJWFOW1"<<std::endl;
			return (false);
		}
	}
	std::cout << "AFEWFOJWFJWFOW2"<<std::endl;
	return (true);
}

ft::Request::Request(std::string buffe, std::string ip)
{
	this->ipv4 = ip;
	this->buffer = buffe;
}

//////////////////////////////////////////

void ft::Request::display(void) const
{
	std::cout << static_cast<int>(method) << "-";
	std::cout << path << "-";
	std::cout << version << std::endl;

	for (const auto [key, value] : fields)
		std::cout << key << ":" << value << std::endl;
	
	std::cout << body << std::endl;
}

void ft::Request::setMethod(const std::string& inMethod)
{
	if (inMethod == "GET")
		method = ft::Method::GET;
	else if (inMethod == "POST")
		method = ft::Method::POST;
	else if (inMethod == "DELETE")
		method = ft::Method::DELETE;
	else
		method = ft::Method::ERR;
}

//////////////////////////////////////////
