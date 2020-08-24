/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:18:37 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:18:37 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class	Sed
{
	private:
		std::ofstream	ofs;
		std::ifstream	ifs;
	public:
		Sed();
		int		openFile(std::string filename);
		void	replace(std::string s1, std::string s2);
		void	closeFile();
		~Sed();
};

#endif