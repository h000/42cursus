/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:20:24 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:20:24 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
	private:
		std::string	name;
		std::string	color;
	public:
		Pony(std::string name, std::string color);
		std::string	getName(void);
		std::string	getColor(void);
		void	eat(void);
		void	run(void);
		void	sleep(void);
		~Pony();
};

#endif