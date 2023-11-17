/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:02:32 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/16 08:10:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

// ====== Constructors ======
Contact::Contact(void)
{
	this->index = 0;
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

// ====== Setters ======
void Contact::SetIndex(int index)
{
	this->index = index;
}

void Contact::SetFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::SetLastName(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::SetNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::SetPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::SetDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

int Contact::GetIndex(void)
{
	return (this->index);
}

// ====== Getters ======
std::string Contact::GetFirstName(void)
{
	return (this->first_name);
}

std::string Contact::GetLastName(void)
{
	return (this->last_name);
}

std::string Contact::GetNickname(void)
{
	return (this->nickname);
}

std::string Contact::GetPhoneNumber(void)
{
	return (this->phone_number);
}

std::string Contact::GetDarkestSecret(void)
{
	return (this->darkest_secret);
}
