/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:06:05 by mcourtoi          #+#    #+#             */
/*   Updated: 2024/02/28 14:50:51 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IrcMessage.hpp"

// Getters //

std::string const        &IrcMessage::get_prefix() const { return this->_prefix; }
std::string const        &IrcMessage::get_command() const { return this->_command; }
std::vector<std::string> &IrcMessage::get_params() { return this->_params; }
std::string const        &IrcMessage::get_end() const { return this->_end; }
bool                      IrcMessage::is_complete() const { return _is_complete; }
