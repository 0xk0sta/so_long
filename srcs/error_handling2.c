/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:00:50 by acostal-          #+#    #+#             */
/*   Updated: 2021/10/28 12:00:51 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_format(char *map)
{
	int	len;
	int	cnt;

	len = ft_strlen(map);
	cnt = 0;
	if (map[len - 1] != 'r' && cnt == 0 && cnt++)
		write(1, &E2, 27);
	if (map[len - 2] != 'e' && cnt == 0 && cnt++)
		write(1, &E2, 27);
	if (map[len - 3] != 'b' && cnt == 0 && cnt++)
		write(1, &E2, 27);
	if (map[len - 4] != '.' && cnt == 0 && cnt++)
		write(1, &E2, 27);
	if (cnt != 0)
		exit(1);
}

int	red_x_handle(int keycode, t_gvars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

void	exit_hook(t_gvars *vars)
{
	ft_free_map(vars);
	exit(0);
}
