/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:54:08 by mcourtoi          #+#    #+#             */
/*   Updated: 2024/01/26 04:38:58 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "Server.hpp"

class	Server;
class	Command;

// TODO : put back sockaddr_in and length
class Client
{
private:

	int	_socket;
	std::string	_name;
	std::string	_nickname;
	struct epoll_event	*_client_event;
	bool	_is_complete;
	std::string	_input;
	bool	_is_input_complete;
	Command	*_command;
	
public:

	Client(int const socket, int const name, int const nickname);
	~Client();

	int	getSocket(void) const;
	std::string	getName(void) const;
	std::string	getNickname(void) const;
	struct epoll_event	*getEvent(void) const;
	bool	getIsComplete() const;
	std::string	getInput() const;
	bool	getIsInputComplete() const;
	Command	*getCommand() const;

	void	setSocket(int const socket);
	void	setName(std::string const name);
	void	setNickname(std::string const nickname);
	void	setEvent();
	void	setIsComplete(bool const yesno);
	void	setInput(std::string const input);
	void	setIsInputComplete(bool const yesno);
	void	setCommand(Command *command);
};

#endif
