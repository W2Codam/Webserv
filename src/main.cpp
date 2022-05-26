/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 17:39:03 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/26 09:41:16 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "CommonNetwork.hpp"
#include "Exchange/Request.hpp"

#define CLIENT_BODY_SIZE 30000

void ft_exit(int lol)
{
	std::cout << "Bye Bye!" << std::endl;
	exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
	int32_t ServerFD, ClientSocket, ValRead;
	ft::SocketAddress Address(AF_INET, htons(8080), INADDR_ANY); // Internet Address on Port 8080 on Localhost

	signal(SIGINT, ft_exit);



	const char* hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

	// NOTE: Maybe use signal to catch ctrl+c to properly exit ?
	// Setup a server class ?

	try // Create internet socket.
	{
        ServerFD = ft::socket(IPV4, TCP, NONE);

		// Should make the kernel release socket resources
		ft::setSocketOption(ServerFD, SOL_SOCKET, SO_REUSEADDR, true, sizeof(int32_t));
		ft::bind(ServerFD, &Address);
		ft::listen(ServerFD, 128);
	}
	catch(const ft::Exception& e)
	{
		ft::exceptionExit(e);
	}
	
	//////////////////////////////////

    while(true)
    {

		// NOTE: Use send and recv functions instead of read and write!

        std::cout << "\n//=/ ...Listening... /=//\n" << std::endl;
        try
        {
            ClientSocket = ft::accept(ServerFD, &Address);

            char buffer[CLIENT_BODY_SIZE] = {0};
			ft::receive(ClientSocket, buffer, CLIENT_BODY_SIZE, 0);
			
			ft::Request Request(buffer); //literally just shits everything into a map
			Request.Display();

			ft::send(ClientSocket, hello, strlen(hello), 0); // send Response
			std::cout << "//=/ Sent Response /=//" << std::endl;
            close(ClientSocket); // End of Exchange
        }
        catch(const ft::Exception& e)
        {
            ft::exceptionExit(e);
        }
    }
	return (EXIT_SUCCESS);
}

// curl --verbose http://localhost:8080/
// --header for custom headers ala "header:123"