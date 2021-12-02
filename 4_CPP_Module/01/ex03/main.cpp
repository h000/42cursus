/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:19:49 by hpark             #+#    #+#             */
/*   Updated: 2020/08/24 12:19:50 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int	main()
{
	ZombieHorde *heap = new ZombieHorde(5);
	heap->announce();
	delete(heap);

	ZombieHorde stack = ZombieHorde(5);
	stack.announce();
	return (0);
}