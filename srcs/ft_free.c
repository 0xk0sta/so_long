/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:37:58 by acostal-          #+#    #+#             */
/*   Updated: 2021/10/28 11:37:59 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	ft_free_map(t_gvars *vars)
{
	int	i;

	i = 0;
	(void)vars;
	while (i < (int)vars->height)
		if (vars->buffer[i])
			free(vars->buffer[i++]);
	if (vars->buffer)
		free(vars->buffer);
	free(vars->m_name);
	ft_free_imgs(vars);
}

int	ft_free_imgs(t_gvars *vars)
{
	free(vars->wall);
	free(vars->exit);
	free(vars->floor);
	free(vars->item);
	free(vars->player);
	return (0);
}

void	destroy_imgs(t_gvars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.floor);
	mlx_destroy_image(vars->mlx, vars->img.item);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_destroy_image(vars->mlx, vars->img.player);
	mlx_destroy_image(vars->mlx, vars->img.exit);
}
