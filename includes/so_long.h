/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:01:49 by acostal-          #+#    #+#             */
/*   Updated: 2021/10/28 12:01:52 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define E0 "Error: wrong route or error opening the map file\n"
# define E1 "Error: Map is not even\n"
# define E2 "Error: wrong map extension\n"
# define TSZ 32
typedef struct s_img
{
	void		*wall;
	void		*player;
	void		*exit;
	void		*floor;
	void		*item;
}t_img;
typedef struct s_gvars
{
	t_img		img;
	char		**buffer;
	char		*wall;
	char		*player;
	char		*exit;
	char		*floor;
	char		*item;
	char		*m_name;
	size_t		height;
	size_t		width;
	void		*mlx;
	void		*mlx_win;
	int			map_fd;
	int			p_count;
	int			e_count;
	int			c_count;
	int			o_items;
	int			move_count;
	int			p_pos[2];
	int			e_pos[2];
}t_gvars;
void	check_map_format(char *map);
void	count_lines(t_gvars *vars);
void	parse_map(t_gvars *vars);
void	count_lines(t_gvars *vars);
void	count_ch(t_gvars *vars, char c);
void	ft_free_map(t_gvars *vars);
void	destroy_imgs(t_gvars *vars);
int		ft_error(t_gvars *vars, int etype);
int		ft_free_imgs(t_gvars *img_lst);
int		check_top_n_bot(t_gvars *vars, int chk);
int		check_count(t_gvars *vars);
int		check_chars(t_gvars *vars, char *line);
int		is_map_even(t_gvars *vars);
int		mlx_initialize(t_gvars *vars);
int		key_hook_handle(int keycode, t_gvars *vars);
void	exit_hook(t_gvars *vars);
int		red_x_handle(int keycode, t_gvars *vars);
#endif
