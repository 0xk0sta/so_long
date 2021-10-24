#include "../includes/so_long.h"

//TODO COMPROBAR QUE HAYA 1 SOLA EXIT y 1 SOLO PLAYER.
//TODO COMPROBAR QUE HAYA AL MENOS 1 ITEM

void	ft_free_map(t_gvars *vars)
{
	int	i;

	i = 0;
	while (i < (int)vars->height)
	{
		if (vars->buffer[i])
			free(vars->buffer[i++]);
	}
	if (vars->buffer)
		free(vars->buffer);
}

void	print_map(t_gvars *vars)
{
	int	i;

	i = -1;
	while (++i < (int)vars->height - 1)
		printf("%s", vars->buffer[i]);
	printf("%s\n", vars->buffer[i]);
	ft_free_map(vars);
	exit((int)write(1, "MAP PRINTED SUCCESSFULLY\n", 25));
}

int 	is_map_even(t_gvars *vars)
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

int	ft_error(t_gvars *vars, int etype)
{
	if (etype == 1)
	{
		ft_free_map(vars);
		return ((int)write(1, &E1, 23));
	}
	return (0);
}

void	init_struct(t_gvars *vars)
{
	vars->buffer = NULL;
	vars->map_fd = 0;
	vars->height = 0;
	vars->m_name = NULL;
}

int	check_top_n_bot(t_gvars *vars, int chk)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (chk == 0)
		j = 0;
	else
		j = vars->height;
	while (i++ < vars->width)
		if (vars->buffer[j][i] != '1')
			return (-1);
	return (0);
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
	}
	return (0);
}

void 	parse_map(t_gvars *vars)
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
	if (is_map_even(vars) == -1 || check_top_n_bot(vars, 1) == -1)
		exit(ft_error(vars, 1));
	close(vars->map_fd);
	print_map(vars);
}

void	count_lines(t_gvars *vars)
{
	char	*buf;

	buf = get_next_line(vars->map_fd);
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
	init_struct(&vars);
	vars.m_name = ft_strdup(argv[1]);
	vars.map_fd = open(argv[1], O_RDONLY);
	if (vars.map_fd <= 0)
		return ((int)write(1, &E0, 49));
	else
		count_lines(&vars);
}
