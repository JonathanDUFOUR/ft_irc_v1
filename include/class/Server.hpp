/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 06:38:07 by jodufour          #+#    #+#             */
/*   Updated: 2024/03/11 07:23:12 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "class/Client.hpp"
#include <netinet/in.h>
#include <vector>

// TODO : change this to a proper value

#define MAX_CLIENTS 3

class Server
{
public:
	// Constructors
	Server(int const port, std::string const &name, std::string const &password = "");

	// Destructor
	~Server(void);

	// Methods
	void start(void);

private:
	// Types
	typedef void (Server::*Command)(Client &sender, std::vector<std::string> const &parameters);
	typedef std::pair<std::string const, Command const> CommandPair;
	typedef std::map<std::string, Command const>        CommandMap;
	typedef CommandMap::const_iterator                  CommandIterator;

	// Shared fields
	static std::set<std::string> const                    _operator_hosts;
	static std::map<std::string, std::string const> const _operator_ids;
	static CommandPair const                              _raw_commands_by_name[];
	static CommandMap const                               _commands_by_name;

	// Fields
	int const         _socket;
	int const         _epoll_socket;
	sockaddr_in const _sock_addr;

	std::string const _name;
	std::string const _version;
	std::string const _password;
	std::string const _compilation_date;
	std::string const _compilation_time;
	std::string const _creation_date;
	std::string const _creation_time;

	std::map<int, Client>             _clients_by_socket;
	std::map<NickName, Client *const> _clients_by_nickname;
	std::map<ChannelName, Channel>    _channels_by_name;

	// Methods
	void _add_client(Client const &client);
	void _remove_client(Client &client, std::string const &quit_msg = DEFAULT_QUIT_MSG);

	void _handle_epoll_events(void);
	void _compute_next_msg_for_a_client(Client &client);
	void _new_client_connection(void);
	void _receive_data_from_client(Client &client);
	void _check_time_of_last_msg(void);

	// Commands
	void _away(Client &sender, std::vector<std::string> const &parameters);
	void _cap(Client &sender, std::vector<std::string> const &parameters);
	void _mode(Client &sender, std::vector<std::string> const &parameters);
	void _nick(Client &sender, std::vector<std::string> const &parameters);
	void _oper(Client &sender, std::vector<std::string> const &parameters);
	void _pass(Client &sender, std::vector<std::string> const &parameters);
	void _ping(Client &sender, std::vector<std::string> const &parameters);
	void _pong(Client &sender, std::vector<std::string> const &parameters);
	void _quit(Client &sender, std::vector<std::string> const &parameters);
	void _user(Client &sender, std::vector<std::string> const &parameters);
	void _join(Client &sender, std::vector<std::string> const &parameters);
	void _part(Client &sender, std::vector<std::string> const &parameters);
	void _topic(Client &sender, std::vector<std::string> const &parameters);
	void _invite(Client &sender, std::vector<std::string> const &parameters);
	void _kick(Client &sender, std::vector<std::string> const &parameters);
	void _privmsg(Client &sender, std::vector<std::string> const &parameters);
	void _notice(Client &sender, std::vector<std::string> const &parameters);
	
};
