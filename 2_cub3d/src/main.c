/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:40:14 by hpark             #+#    #+#             */
/*   Updated: 2020/06/25 13:45:19 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_img(t_vars *vars)
{
	vars->img.img_ptr = mlx_new_image(vars->mlx,
	vars->pars.resolution_w, vars->pars.resolution_h);
	vars->img.data = (int *)mlx_get_data_addr(vars->img.img_ptr,
	&vars->img.bpp, &vars->img.size_line, &vars->img.endian);
	vars->tex[0].img_ptr = mlx_xpm_file_to_image(vars->mlx,
	vars->pars.no_path, &vars->texwid, &vars->texhei);
	vars->tex[0].data = (int *)mlx_get_data_addr(vars->tex[0].img_ptr,
	&vars->tex[0].bpp, &vars->tex[0].size_line, &vars->tex[0].endian);
	vars->tex[1].img_ptr = mlx_xpm_file_to_image(vars->mlx,
	vars->pars.so_path, &vars->texwid, &vars->texhei);
	vars->tex[1].data = (int *)mlx_get_data_addr(vars->tex[1].img_ptr,
	&vars->tex[1].bpp, &vars->tex[1].size_line, &vars->tex[1].endian);
	vars->tex[2].img_ptr = mlx_xpm_file_to_image(vars->mlx,
	vars->pars.we_path, &vars->texwid, &vars->texhei);
	vars->tex[2].data = (int *)mlx_get_data_addr(vars->tex[2].img_ptr,
	&vars->tex[2].bpp, &vars->tex[2].size_line, &vars->tex[2].endian);
	vars->tex[3].img_ptr = mlx_xpm_file_to_image(vars->mlx,
	vars->pars.ea_path, &vars->texwid, &vars->texhei);
	vars->tex[3].data = (int *)mlx_get_data_addr(vars->tex[3].img_ptr,
	&vars->tex[3].bpp, &vars->tex[3].size_line, &vars->tex[3].endian);
	vars->tex[4].img_ptr = mlx_xpm_file_to_image(vars->mlx,
	vars->pars.sp_path, &vars->texwid, &vars->texhei);
	vars->tex[4].data = (int *)mlx_get_data_addr(vars->tex[4].img_ptr,
	&vars->tex[4].bpp, &vars->tex[4].size_line, &vars->tex[4].endian);
}

int		exit_game(void)
{
	exit(0);
}

int		main(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars*)malloc(sizeof(t_vars));
	if (!parsing(&(vars->pars), argv[1], vars))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!info_error(&(vars->pars)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	vars->mlx = mlx_init();
	get_img(vars);
	render(vars);
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		return (ft_write_bmp_file(vars));
	vars->win = mlx_new_window(vars->mlx,
	vars->pars.resolution_w, vars->pars.resolution_h, "Cub3d");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, &key_pressed, vars);
	mlx_hook(vars->win, 17, 1L << 0, &exit_game, vars);
	mlx_loop(vars->mlx);
}
