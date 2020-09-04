/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 22:41:42 by hpark             #+#    #+#             */
/*   Updated: 2020/09/04 22:41:43 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return (0);
}