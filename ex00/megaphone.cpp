/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:08:38 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/10 17:11:25 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_in_upper_case(char **str)
{
	int i = 0;
	int j = 0;

	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			std::cout << (char)std::toupper(str[i][j]);
			j++;
		}
		if (str[i + 1])
			std::cout << " ";
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		print_in_upper_case(argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
