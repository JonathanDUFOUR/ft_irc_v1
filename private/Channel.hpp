/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:04:52 by mcourtoi          #+#    #+#             */
/*   Updated: 2024/01/26 04:04:54 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "Server.hpp"
# include "Client.hpp"

class	Server;
class	Client;

class Channel
{
private :

	std::string _name;
	std::string	_topic;
	std::vector<Client *> _clients;
	std::vector<Client *> _operators;

public:

	Channel(std::string name);
	~Channel();

	std::string	getName(void);
	std::string	getTopic(void);
	std::vector<Client *>	getClients(void);
	std::vector<Client *>	getOperators(void);

	void	setName(std::string name);
	void	setTopic(std::string topic);
	void	setClients(std::vector<Client *> clients);
	void	setOperators(std::vector<Client *> operators);
	void	addClient(Client *client);
	void	addOperator(Client *client);
	void	removeClient(Client *client);
	void	removeOperator(Client *client);
};

#endif
