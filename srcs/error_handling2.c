#include "../includes/so_long.h"

void	check_map_format(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'r')
		exit((int)write(1, &E2, 27));
	if (map[len - 2] != 'e')
		exit((int)write(1, &E2, 27));
	if (map[len - 3] != 'b')
		exit((int)write(1, &E2, 27));
	if (map[len - 4] != '.')
		exit((int)write(1, &E2, 27));
}

void	exit_hook(t_gvars *vars)
{
	ft_free_map(vars);
	exit(0);
}
