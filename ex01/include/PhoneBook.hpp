/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:52:54 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/16 08:27:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACT_MAX 8
# define FIELD_SIZE 10
# define FIELD_SEPARATOR '|'
# define FIELD_EDGE '|'

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>
# include <sstream>

class PhoneBook
{
	Contact contacts[CONTACT_MAX];
	int contact_count;
	int GetNextIndex(void);
	std::string GetUserInput(std::string message);
	int GetUserIndex(void);
	void PrintHeader(void);
	void PrintContact(int index);
	void PrintContactList(void);

  public:
	PhoneBook(void);
	// ~PhoneBook(void);
	void AddContact(void);
	void SearchContact(void);
};

#endif
