/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:24:18 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/16 08:10:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


# include <iostream>
# include <string>

class Contact
{
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact(void);
	// ~Contact(void);
	void SetIndex(int index);
	void SetFirstName(std::string first_name);
	void SetLastName(std::string last_name);
	void SetNickname(std::string nickname);
	void SetPhoneNumber(std::string phone_number);
	void SetDarkestSecret(std::string darkest_secret);
	int GetIndex(void);
	std::string GetFirstName(void);
	std::string GetLastName(void);
	std::string GetNickname(void);
	std::string GetPhoneNumber(void);
	std::string GetDarkestSecret(void);
};

#endif
