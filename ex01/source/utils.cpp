/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 07:28:45 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/29 16:09:47 by joakoeni         ###   ########.fr       */
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
		value = 0;
		while (true)
		{
			std::cout << message;
			if (!std::getline(std::cin, input))
				return (0);
			std::stringstream ss(input);
			if (ss >> value && ss.eof())
				break ;
			else
				std::cout << "Invalid number. Please enter a valid integer." << std::endl;
		}
		return (value);
	}
} // namespace utils
