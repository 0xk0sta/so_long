/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:38:29 by acostal-          #+#    #+#             */
/*   Updated: 2021/10/28 11:38:31 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_gvars *vars)
{
	size_t	i;

	i = 0;
	vars->map_fd = open(vars->m_name, O_RDONLY);
	vars->buffer = malloc(sizeof(char *) * vars->height);
	vars->buffer[i] = get_next_line(vars->map_fd);
	if (check_top_n_bot(vars, 0) == -1)
		exit(ft_error(vars, 1));
	while (++i < vars->height)
	{
		vars->buffer[i] = get_next_line(vars->map_fd);
		if (check_chars(vars, vars->buffer[i]) == -1)
		{
			vars->height = i + 1;
			exit(ft_error(vars, 1));
		}
	}
	if (is_map_even(vars) == -1 || check_top_n_bot(vars, 1) == -1
		|| check_count(vars) == -1)
		exit(ft_error(vars, 1));
	close(vars->map_fd);
}

void	count_lines(t_gvars *vars)
{
	char	*buf;

	buf = get_next_line(vars->map_fd);
	if (!buf)
		exit((int)write(1, "Error: Empty map\n", 17));
	vars->width = (ft_strlen(buf) - 1);
	while (buf)
	{
		free(buf);
		vars->height++;
		buf = get_next_line(vars->map_fd);
	}
	close(vars->map_fd);
	parse_map(vars);
}
