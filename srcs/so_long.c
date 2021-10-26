#include "../includes/so_long.h"

//TODO COMPROBAR QUE HAYA 1 SOLA EXIT y 1 SOLO PLAYER.
//TODO COMPROBAR QUE HAYA AL MENOS 1 ITEM

void	print_map(t_gvars *vars)
{
	int	i;

	i = -1;
	printf("H: %zu\n", vars->height);
	while (++i < (int)vars->height - 1)
		printf("%s  %d\t", vars->buffer[i], i);
	printf("%s\n", vars->buffer[i]);
	ft_free_map(vars);
	exit((int)write(1, "MAP PRINTED SUCCESSFULLY\n", 25));
}

int	ft_error(t_gvars *vars, int etype)
{
	if (etype == 1)
	{
		ft_free_map(vars);
		ft_free_imgs(vars);
		return ((int)write(1, &E1, 23));
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
	vars->move_count = 0;
	vars->exit = ft_strdup("../img/door.png");
	vars->wall = ft_strdup("../img/wall.png");
	vars->floor = ft_strdup("../img/floor.png");
	vars->item = ft_strdup("../img/item.png");
	vars->player = ft_strdup("../img/player.png");
}

void leaks()
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	t_gvars	vars;

	atexit(leaks);
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
