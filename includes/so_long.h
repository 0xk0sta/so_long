#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define E0 "Error: wrong route or error opening the map file\n"
# define E1 "Error: Map is not even\n"
# define E2 "Error: wrong map extension\n"
# define tsz 32
typedef struct s_gvars
{
	char		**buffer;
	int			map_fd;
	size_t		height;
	size_t		width;
	char		*m_name;
	int			p_count;
	int			e_count;
	int			c_count;
	int			move_count;
	char		*wall;
	char		*player;
	char		*exit;
	char		*floor;
	char		*item;
	void		*mlx;
	void		*mlx_win;
}t_gvars;
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}t_mlx;
void	check_map_format(char *map);
int		ft_error(t_gvars *vars, int etype);
void	ft_free_map(t_gvars *vars);
void	print_map(t_gvars *vars);
int		ft_free_imgs(t_gvars *img_lst);
void	count_lines(t_gvars *vars);
void	parse_map(t_gvars *vars);
void	count_lines(t_gvars *vars);
int		check_top_n_bot(t_gvars *vars, int chk);
int		check_count(t_gvars *vars);
void	count_ch(t_gvars *vars, char c);
int		check_chars(t_gvars *vars, char *line);
int		is_map_even(t_gvars *vars);
int		mlx_initialize(t_gvars *vars);
#endif
