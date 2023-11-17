/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 05:07:05 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/15 13:06:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

static void print_manual(void)
{
	std::cout << "Commands	:" << std::endl;
	std::cout << "ADD		: Add a new contact" << std::endl;
	std::cout << "SEARCH	: Search a contact" << std::endl;
	std::cout << "EXIT		: Exit the program" << std::endl;
}

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
	while (input != "EXIT")
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
			print_manual();
		}
	}

	return (0);
}
