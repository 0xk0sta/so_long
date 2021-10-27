/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:10:10 by                   #+#    #+#             */
/*   Updated: 2021/10/27 09:34:40 by                  ###   ########.fr       */
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

void 	xpm_to_img(t_gvars *vars, t_img *img_lst)
{
	int	sz;

	sz = 64;
	img_lst->item = mlx_xpm_file_to_image(vars->mlx, vars->item, &sz, &sz);
	img_lst->floor = mlx_xpm_file_to_image(vars->mlx, vars->floor, &sz, &sz);
	img_lst->wall = mlx_xpm_file_to_image(vars->mlx, vars->wall, &sz, &sz);
	img_lst->exit = mlx_xpm_file_to_image(vars->mlx, vars->exit, &sz, &sz);
	img_lst->player = mlx_xpm_file_to_image(vars->mlx, vars->player, &sz, &sz);
}

void	put_wall_n_floor(t_gvars *vars, t_img *img, int i, int j)
{
	else if (vars->buffer[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall,
								tsz * j, tsz * i);
	else if (vars->buffer[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img->floor,
								tsz * j, tsz * i);
}

void	check_n_print(t_gvars *vars, t_img *img, int i, int j)
{
	void	*p;

	if (vars->buffer[i][j] == 'C')
	{
		p = mlx_put_image_to_window(vars->mlx, vars->win, img->floor,
				tsz * j, tsz * i);
		mlx_put_image_to_window(vars->mlx, vars->win, img->item,
			tsz * j, tsz * i);
	}
	else if (vars->buffer[i][j] == 'P')
	{
		p = mlx_put_image_to_window(vars->mlx, vars->win, img->floor,
				tsz * j, tsz * i);
		mlx_put_image_to_window(vars->mlx, vars->win, img->player,
			tsz * j, tsz * i);
	}
	else if (vars->buffer[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, img->exit,
			tsz * j, tsz * i);
	else if (vars->buffer[i][j] == '1' || vars->buffer[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall,
			tsz * j, tsz * i);
	else if (vars->buffer[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img->floor,
			tsz * j, tsz * i);
}

void 	first_draw(t_gvars *vars, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)vars->height)
	{
		j = -1;
		while (++j < (int)vars->width)
		{
			check_n_print(vars, img, i, j);
		}
	}
}

int	mlx_initialize(t_gvars *vars)
{
	t_img	img_lst;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * tsz,
			vars->height * tsz, "so_long");
	xpm_to_img(vars, &img_lst);
	first_draw(vars, &img_lst);
	mlx_key_hook(vars->win, key_hook_handle, vars);
	mlx_loop(vars->mlx);
	return (0);
}