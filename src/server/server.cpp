/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:55:39 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/11/27 16:55:51 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <cerrno>
#include <sys/types.h> 

/**
 * @brief Create a socket object
 * 
 * @todo create an exception to be thrown for more proper use
 * 
 * @return socket create / if failure exit with EXIT_FAILURE
 */

int	create_socket()
{
	int fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_socket == -1)
	{
		std::cerr << "Failed to create socket. errno: " << errno << std::endl;
		exit (EXIT_FAILURE);
	}
	return fd_socket;
}

/**
 * @brief create a struct sockaddr to listen to chosen port on any addresses  
 * 
 * @param fd_socket 
 * @return sockaddr_in& 
 */
sockaddr_in	bind_assign_sockaddr(int fd_socket, int chosen_addr)
{
	sockaddr_in	sock_addr;
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(chosen_addr); 
	sock_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(fd_socket, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
	{
		std::cerr << "Failed to bind address. errno: " << errno << std::endl;
		exit (EXIT_FAILURE);
	}
	return sock_addr;
}

void	read_and_respond(int connection)
{
	std::string buffer(100, '\0');

	while (buffer != "quit\n")
	{
		ssize_t bytes_read = read(connection, &buffer[0], buffer.size() - 1); // Laisser un espace pour le caractère de fin de chaîne
		if (bytes_read <= 0)
		{
			if (bytes_read == 0)
			{
				// La connexion a été fermée par le client
				std::cout << "Client disconnected." << std::endl;
			}
			else {
				// Une erreur de lecture
				std::cerr << "Read failed. errno: " << errno << std::endl;
			}
			return;
		}

		buffer[bytes_read] = '\0'; // Assurer la terminaison de la chaîne
		std::cout << "The message was: " << buffer << '\n';

		buffer.resize(bytes_read - 2);
		if (buffer == "quit")
			return;
		buffer.assign(100, '\0');

		std::string response = "got it\n";
		send(connection, response.c_str(), response.size(), 0);
	}
}

void	create_server(int chosen_addr)
{
	int	fd_socket = create_socket();
	sockaddr_in	sock_addr = bind_assign_sockaddr(fd_socket, chosen_addr);
	int	connection;

	if (listen(fd_socket, 10) < 0) 
	{
		std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}
	socklen_t	addr_len = sizeof(sock_addr);
	connection = accept(fd_socket, (struct sockaddr*)&sock_addr, (socklen_t*)&addr_len);
	if (connection < 0)
	{
		std::cout << "Failed to connect. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}
	
	read_and_respond(connection);

	close(connection);
	close(fd_socket);
}
