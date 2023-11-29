/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:08:37 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/29 16:08:23 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
	next_index = -1;
}

void PhoneBook::PrintHelp()
{
	std::cout << "ADD	: Add a new contact" << std::endl;
	std::cout << "SEARCH	: Search a contact" << std::endl;
	std::cout << "EXIT	: Exit the program" << std::endl;
}

std::string PhoneBook::GetUserInput(std::string message)
{
	std::string input;
	while ((input.empty() || !IsValidInput(input)) && !std::cin.eof())
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (input.empty() || !IsValidInput(input))
			std::cout << "Invalid input" << std::endl;
	}
	return (input);
}

bool PhoneBook::IsValidInput(std::string str)
{
	int str_len = str.length();

	for (int i = 0; i < str_len; i++)
	{
		if (str[i] == '\t' || str.find('\033') != std::string::npos)
			return (false);
	}
	return (true);
}

int PhoneBook::GetUserIndex(void)
{
	int	index;

	index = utils::get_user_input_as_int("Please enter an index: ");
	while ((index < 1 || index > this->contact_count || index > CONTACT_MAX) && !std::cin.eof())
	{
		std::cout << "Wrong index" << std::endl;
		this->PrintPhoneBook();
		index = utils::get_user_input_as_int("Please enter a valid index: ");
	}
	return (index - 1);
}

void PhoneBook::PrintHeader(void)
{
	std::cout << FIELD_EDGE <<
		std::setw(FIELD_SIZE) <<
		"Index" << FIELD_SEPARATOR << std::setw(FIELD_SIZE) <<
		"First name" << FIELD_SEPARATOR << std::setw(FIELD_SIZE) <<
		"Last name" << FIELD_SEPARATOR << std::setw(FIELD_SIZE) <<
		"Nickname" << FIELD_EDGE << std::endl;
}


void PhoneBook::PrintPhoneBook(void)
{
	this->PrintHeader();
	this->PrintContactList();
	this->PrintHeader();
}

void PhoneBook::PrintContact(int index)
{
	if (std::cin.eof())
		return ;
	std::cout << "Index: " << this->contacts[index].GetIndex() + 1 << std::endl;
	std::cout << "First name: " << this->contacts[index].GetFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[index].GetLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].GetNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].GetDarkestSecret() << std::endl;
}

std::string PhoneBook::TruncatedString(std::string str)
{
	if (str.length() > FIELD_SIZE)
		return (str.substr(0, FIELD_SIZE - 1) + '.');
	return (str);
}

void PhoneBook::PrintContactList(void)
{
	for (int i = 0; i < this->contact_count && i < CONTACT_MAX; i++)
	{
		std::cout << FIELD_EDGE << std::setw(FIELD_SIZE) <<
			this->contacts[i].GetIndex() + 1 << 
			FIELD_SEPARATOR << std::setw(FIELD_SIZE) <<
			TruncatedString(this->contacts[i].GetFirstName()) <<
			FIELD_SEPARATOR << std::setw(FIELD_SIZE) <<
			TruncatedString(this->contacts[i].GetLastName()) << 
			FIELD_SEPARATOR << std::setw(FIELD_SIZE) <<
			TruncatedString(this->contacts[i].GetNickname()) <<
			FIELD_EDGE << std::endl;
	}
}

void PhoneBook::SearchContact(void)
{
	int	index;

	if (this->contact_count == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	this->PrintPhoneBook();
	std::cout << "Which contact would you display ?" << std::endl;
	index = this->GetUserIndex();
	this->PrintContact(index);
}

void PhoneBook::AddContact(void)
{
	Contact	new_contact;

	std::string input;
	input = this->GetUserInput("Please enter the first name: ");
	new_contact.SetFirstName(input);
	input = this->GetUserInput("Please enter the last name: ");
	new_contact.SetLastName(input);
	input = this->GetUserInput("Please enter the nickname: ");
	new_contact.SetNickname(input);
	input = this->GetUserInput("Please enter the phone number: ");
	new_contact.SetPhoneNumber(input);
	input = this->GetUserInput("Please enter the darkest secret: ");
	new_contact.SetDarkestSecret(input);
	GetNextIndex();
	new_contact.SetIndex(next_index);
	contacts[next_index] = new_contact;
	this->contact_count++;
}

void PhoneBook::GetNextIndex(void)
{
	next_index++;
	if (next_index == CONTACT_MAX)
		next_index = 0;
}
