/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:31:04 by mcourtoi          #+#    #+#             */
/*   Updated: 2024/03/05 02:44:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Server.hpp"
#include <cstdlib>
#include <iostream>

// TODO : create a checker for the arguments
int main(int const ac, char const *const *const av)
{
	if (ac != 3)
	{
		std::cerr << "incorrect number of arguments\n";
		return 1;
	}

	Server myserver = Server(atoi(av[1]), "MyServer", std::string(av[2]));

	try
	{
		myserver.start();
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
