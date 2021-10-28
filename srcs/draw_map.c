/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:00:22 by acostal-          #+#    #+#             */
/*   Updated: 2021/10/28 12:00:23 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	xpm_to_img(t_gvars *vars)
{
	int	sz;

	sz = 32;
	vars->img.item = mlx_xpm_file_to_image(vars->mlx, vars->item, &sz, &sz);
	vars->img.floor = mlx_xpm_file_to_image(vars->mlx, vars->floor, &sz, &sz);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, vars->wall, &sz, &sz);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx, vars->exit, &sz, &sz);
	vars->img.player = mlx_xpm_file_to_image(vars->mlx, vars->player, &sz, &sz);
}

void	check_n_print(t_gvars *vars, int i, int j)
{
	if (vars->buffer[i][j] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			TSZ * j, TSZ * i);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.item,
			TSZ * j, TSZ * i);
	}
	else if (vars->buffer[i][j] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			TSZ * j, TSZ * i);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.player,
			TSZ * j, TSZ * i);
	}
	else if (vars->buffer[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.exit,
			TSZ * j, TSZ * i);
	else if (vars->buffer[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.wall,
			TSZ * j, TSZ * i);
	else if (vars->buffer[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			TSZ * j, TSZ * i);
}

static void	store_positions(t_gvars *vars, int i, int j)
{
	int	z;

	z = -1;
	if (vars->buffer[i][j] == 'P')
	{
		vars->p_pos[0] = i * TSZ;
		vars->p_pos[1] = j * TSZ;
	}
	else if (vars->buffer[i][j] == 'E')
	{
		vars->e_pos[0] = i * TSZ;
		vars->e_pos[1] = j * TSZ;
	}
}

static void	first_draw(t_gvars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)vars->height)
	{
		j = -1;
		while (++j < (int)vars->width)
		{
			check_n_print(vars, i, j);
			store_positions(vars, i, j);
		}
	}
}

int	mlx_initialize(t_gvars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, vars->width * TSZ,
			vars->height * TSZ, "so_long");
	xpm_to_img(vars);
	first_draw(vars);
	mlx_key_hook(vars->mlx_win, key_hook_handle, vars);
	mlx_hook(vars->mlx_win, 17, 1L << 17, red_x_handle, vars);
	mlx_loop(vars->mlx);
	return (0);
}
