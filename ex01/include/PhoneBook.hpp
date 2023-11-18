/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:52:54 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/18 14:00:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACT_MAX 8
# define FIELD_SIZE 10
# define FIELD_SEPARATOR '|'
# define FIELD_EDGE '|'

# include "Contact.hpp"
# include "utils.hpp"
# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>

class PhoneBook
{
	Contact contacts[CONTACT_MAX];
	int contact_count;
	int next_index;
	std::string GetUserInput(std::string message);
	std::string TruncatedString(std::string);
	bool IsValidInput(std::string str);
	int GetUserIndex(void);
	void GetNextIndex(void);
	void PrintHeader(void);
	void PrintContact(int index);
	void PrintContactList(void);
	void PrintPhoneBook(void);

  public:
	PhoneBook(void);
	// ~PhoneBook(void);
	void PrintHelp(void);
	void AddContact(void);
	void SearchContact(void);
};

#endif
