/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 07:28:45 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/18 07:29:07 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

namespace utils
{
	int	get_user_input_as_int(const std::string &message)
	{
		int	value;

		std::string input;
		while (true)
		{
			std::cout << message;
			std::getline(std::cin, input);
			std::stringstream ss(input);
			if (ss >> value && ss.eof())
				break ;
			else
				std::cout << "Invalid number. Please enter a valid integer." << std::endl;
		}
		return (value);
	}
} // namespace utils
