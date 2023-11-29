/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 05:07:05 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/29 15:34:37 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

static std::string str_toupper(std::string str)
{
	std::string str_upper;
	for (size_t i = 0; i < str.length(); i++)
		str_upper += toupper(str[i]);
	return (str_upper);
}

int main(void)
{
	PhoneBook PhoneBook;
	std::string input;
	while (input != "EXIT" && !std::cin.eof())
	{
		std::cout << "Please enter a command: ";
		std::getline(std::cin, input);
		input = str_toupper(input);
		if (input == "ADD")
			PhoneBook.AddContact();
		else if (input == "SEARCH")
			PhoneBook.SearchContact();
		else if (input != "EXIT")
		{
			std::cout << "Invalid command" << std::endl;
		PhoneBook.PrintHelp();
		}
	}

	return (0);
}
