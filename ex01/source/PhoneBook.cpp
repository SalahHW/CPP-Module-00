/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:08:37 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/16 08:56:56 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(void) { this->contact_count = 0; }

std::string PhoneBook::GetUserInput(std::string message) {
  std::string input;
  while (input.empty()) {
    std::cout << message;
    std::getline(std::cin, input);
    if (input.empty()) std::cout << "Invalid input" << std::endl;
  }
  return (input);
}

int PhoneBook::GetUserIndex(void) {
  std::string input;
  int index = 0;
  std::stringstream ss;
  while (input.empty()) {
    std::cout << "Please enter the index: ";
    std::getline(std::cin, input);
    if (input.empty()) std::cout << "Invalid input" << std::endl;
  }
  ss << input;
  ss >> index;
  return (index - 1);
}

void PhoneBook::PrintHeader(void) {
  std::cout << FIELD_EDGE << std::setw(FIELD_SIZE) << "Index" << FIELD_SEPARATOR
            << std::setw(FIELD_SIZE) << "First name" << FIELD_SEPARATOR
            << std::setw(FIELD_SIZE) << "Last name" << FIELD_SEPARATOR
            << std::setw(FIELD_SIZE) << "Nickname" << FIELD_EDGE << std::endl;
}

void PhoneBook::PrintContactList(void) {
  for (int i = 0; i < this->contact_count; i++) {
    std::cout << FIELD_EDGE << std::setw(FIELD_SIZE)
              << this->contacts[i].GetIndex() << FIELD_SEPARATOR
              << std::setw(FIELD_SIZE) << this->contacts[i].GetFirstName()
              << FIELD_SEPARATOR << std::setw(FIELD_SIZE)
              << this->contacts[i].GetLastName() << FIELD_SEPARATOR
              << std::setw(FIELD_SIZE) << this->contacts[i].GetNickname()
              << FIELD_EDGE << std::endl;
  }
}

void PhoneBook::PrintContact(int index) {
  std::cout << "Index: " << this->contacts[index].GetIndex() << std::endl;
  std::cout << "First name: " << this->contacts[index].GetFirstName()
            << std::endl;
  std::cout << "Last name: " << this->contacts[index].GetLastName()
            << std::endl;
  std::cout << "Nickname: " << this->contacts[index].GetNickname() << std::endl;
  std::cout << "Phone number: " << this->contacts[index].GetPhoneNumber()
            << std::endl;
  std::cout << "Darkest secret: " << this->contacts[index].GetDarkestSecret()
            << std::endl;
}

void PhoneBook::SearchContact(void) {
  if (this->contact_count == 0) {
    std::cout << "No contact to search" << std::endl;
    return;
  }
  PrintHeader();
  PrintContactList();
  std::cout << "Which contact would you display ?" << std::endl;
  int index = this->GetUserIndex();
  this->PrintContact(index);
}

void PhoneBook::AddContact(void) {
  Contact new_contact;
  std::string input;
  int index;

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
  index = this->GetNextIndex();
  new_contact.SetIndex(index);
  this->contacts[index - 1] = new_contact;
  this->contact_count++;
}

int PhoneBook::GetNextIndex(void) {
  if (this->contact_count < CONTACT_MAX)
    return (this->contact_count + 1);
  else
    return (this->contact_count % CONTACT_MAX + 1);
}
