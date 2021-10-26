/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:10:10 by                   #+#    #+#             */
/*   Updated: 2021/10/26 16:16:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
/*
 *
 * aKey = 0;
 * dKey = 2;
 * upArrow = 13;
 * sKey = 1;
 * esc = 53;
*/

int	key_hook_handle(int keycode, t_gvars *vars)
{
	if (keycode == 53)
	{
		ft_free_map(vars);
		ft_free_imgs(vars);
		exit(0);
	}
	if (keycode == 0)
	{
		printf("Total moves: %d\n", vars->move_count++);
	}
	if (keycode == 1)
	{
		printf("Total moves: %d\n", vars->move_count++);
	}
	if (keycode == 13)
	{
		printf("Total moves: %d\n", vars->move_count++);
	}
	if (keycode == 2)
	{
		printf("Total moves: %d\n", vars->move_count++);
	}
	return (0);
}

int	mlx_initialize(t_gvars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, vars->width * tsz,
			vars->height * tsz, "Hola");
	mlx_key_hook(vars->mlx_win, key_hook_handle, vars);
	mlx_loop(vars->mlx);
	return (0);
}