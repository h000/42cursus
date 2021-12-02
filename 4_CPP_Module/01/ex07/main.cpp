/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:18:26 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:18:26 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	Sed	sed;

	if (argc != 4)
	{
		std::cout << "Error: Invalid Number Of Arguments" << std::endl;
		return (0);
	}
	if (sed.openFile(argv[1]))
	{
		sed.replace(argv[2], argv[3]);
		sed.closeFile();
	}
	else
		std::cout << "Error: Cannot Open File" << std::endl;
}