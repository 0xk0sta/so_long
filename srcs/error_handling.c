/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:00:29 by acostal-          #+#    #+#             */
/*   Updated: 2021/10/28 12:00:30 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_even(t_gvars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (++i < vars->height - 1)
		if (ft_strlen(vars->buffer[i]) != ft_strlen(vars->buffer[j++]))
			return (-1);
	if (ft_strlen(vars->buffer[i - 1]) != ft_strlen(vars->buffer[j]) + 1)
		return (-1);
	i = -1;
	return (0);
}

int	check_top_n_bot(t_gvars *vars, int chk)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (chk == 0)
	{
		j = 0;
		vars->width = vars->width;
	}
	else
		j = vars->height;
	while (i < vars->width)
		if (vars->buffer[j][++i] != '1')
			return (-1);
	return (0);
}

int	check_count(t_gvars *vars)
{
	if (vars->p_count != 1)
		return (-1);
	if (vars->e_count != 1)
		return (-1);
	if (vars->c_count < 1)
		return (-1);
	return (0);
}

void	count_ch(t_gvars *vars, char c)
{
	if (c == 'P')
		vars->p_count++;
	if (c == 'E')
		vars->e_count++;
	if (c == 'C')
		vars->c_count++;
}

int	check_chars(t_gvars *vars, char *line)
{
	size_t	i;

	i = 0;
	if (line[0] != '1' || line[vars->width - 1] != '1')
		return (-1);
	while (++i < vars->width - 1)
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C'
				|| line[i] == 'E' || line[i] == 'P'))
			return (-1);
		else
			count_ch(vars, line[i]);
	}
	return (0);
}
