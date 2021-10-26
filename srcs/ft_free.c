#include "../includes/so_long.h"
void	ft_free_map(t_gvars *vars)
{
	int	i;

	i = 0;
	while (i < (int)vars->height)
		if (vars->buffer[i])
			free(vars->buffer[i++]);
	if (vars->buffer)
		free(vars->buffer);
	free(vars->m_name);
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
