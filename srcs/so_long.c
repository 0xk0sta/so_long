#include "../includes/so_long.h"

int	ft_error(t_gvars *vars, int etype)
{
	if (etype == 1)
	{
		ft_free_map(vars);
		return ((int)write(1, &E1, 23));
	}
	if (etype == 2)
	{
		ft_free_map(vars);
		destroy_imgs(vars);
		write(1, "Congrats, you finished the game!\n", 33);
		return (0);
	}
	return (0);
}

static void	init_struct(t_gvars *vars)
{
	vars->buffer = NULL;
	vars->map_fd = 0;
	vars->height = 0;
	vars->width = 0;
	vars->m_name = NULL;
	vars->e_count = 0;
	vars->c_count = 0;
	vars->p_count = 0;
	vars->move_count = 1;
	vars->o_items = 0;
	vars->exit = ft_strdup("./img/door.xpm");
	vars->wall = ft_strdup("./img/wall.xpm");
	vars->floor = ft_strdup("./img/floor.xpm");
	vars->item = ft_strdup("./img/item.xpm");
	vars->player = ft_strdup("./img/player.xpm");
}

int	main(int argc, char **argv)
{
	t_gvars	vars;

	if (argc != 2)
		return ((int)write(1, "Usage: ./so_long map.ber\n", 25));
	check_map_format(argv[1]);
	init_struct(&vars);
	vars.m_name = ft_strdup(argv[1]);
	vars.map_fd = open(argv[1], O_RDONLY);
	if (vars.map_fd <= 0)
	{
		ft_free_imgs(&vars);
		return ((int) write(1, &E0, 49));
	}
	else
		count_lines(&vars);
	mlx_initialize(&vars);
}
