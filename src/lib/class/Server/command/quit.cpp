/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:25:39 by jodufour          #+#    #+#             */
/*   Updated: 2024/03/11 10:16:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Server.hpp"
#include "replies.hpp"

/**
 * @brief Marks a user as about to be disconnected and sends an ERROR message to them.
 *
 * @param sender The client that sent the command.
 * @param parameters The parameters of the command.
 *
 * @throw `std::exception` if a function of the C++ standard library critically fails.
 */
void Server::_quit(Client &sender, std::vector<std::string> const &parameters)
{
	if (!sender.has_mode(AlreadySentUser))
		return sender.append_formatted_reply_to_msg_out(ERR_NOTREGISTERED);

	sender.append_to_msg_out(sender.prefix() + "ERROR :" + (parameters.empty() ? DEFAULT_QUIT_MESSAGE : parameters[0]));
	sender.set_mode(IsAboutToBeDisconnected);
}
