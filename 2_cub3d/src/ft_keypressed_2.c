/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypressed_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:39:12 by hpark             #+#    #+#             */
/*   Updated: 2020/06/25 13:39:13 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_vars *vars)
{
	if (vars->pars.map[(int)(vars->posx + vars->dirx)][(int)(vars->posy)]
	!= '1')
		vars->posx += vars->dirx * vars->moving_speed;
	if (vars->pars.map[(int)(vars->posx)][(int)(vars->posy + vars->diry)]
	!= '1')
		vars->posy += (vars->diry) * vars->moving_speed;
}

void	go_backward(t_vars *vars)
{
	if (vars->pars.map[(int)(vars->posx - vars->dirx)][(int)(vars->posy)]
	!= '1')
		vars->posx -= vars->dirx * vars->moving_speed;
	if (vars->pars.map[(int)(vars->posx)][(int)(vars->posy - vars->diry)]
	!= '1')
		vars->posy -= vars->diry * vars->moving_speed;
}

void	go_right(t_vars *vars)
{
	if (vars->pars.map[(int)(vars->posx + vars->planex)][(int)(vars->posy)]
	!= '1')
		vars->posx += (vars->planex) * vars->moving_speed;
	if (vars->pars.map[(int)(vars->posx)][(int)(vars->posy + vars->planey)]
	!= '1')
		vars->posy += (vars->planey) * vars->moving_speed;
}

void	go_left(t_vars *vars)
{
	if (vars->pars.map[(int)(vars->posx - vars->planex)][(int)(vars->posy)]
	!= '1')
		vars->posx -= (vars->planex) * vars->moving_speed;
	if (vars->pars.map[(int)(vars->posx)][(int)(vars->posy - vars->planey)]
	!= '1')
		vars->posy -= (vars->planey) * vars->moving_speed;
}
