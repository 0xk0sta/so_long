#include "../includes/so_long.h"
/*
 *
 * esc = 53;
 * aKey = 0;
 * dKey = 2;
 * upArrow = 13;
 * sKey = 1;
 *
 * pos storage format:
 * first pos = y;
 * second pos = x;
 * Left = x - 32
 * Right = x + 32
 * Up = y - 32
 * Down = y + 32
*/
void	up_move(t_gvars *vars)
{
	char	c;

	c = vars->buffer[vars->p_pos[0] / TSZ - 1][vars->p_pos[1] / TSZ];
	if (c == 'C' || c == '0')
	{
		if (c == 'C')
			vars->o_items++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1], vars->p_pos[0]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1], vars->p_pos[0] - TSZ);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.player,
			vars->p_pos[1], vars->p_pos[0] - TSZ);
		vars->buffer[vars->p_pos[0] / TSZ][vars->p_pos[1] / TSZ] = '0';
		vars->p_pos[0] -= 32;
		printf("Total moves: %d\n", vars->move_count++);
	}
	else if (c == 'E' && vars->o_items == vars->c_count)
		exit(ft_error(vars, 2));
}

void	down_move(t_gvars *vars)
{
	char	c;

	c = vars->buffer[vars->p_pos[0] / TSZ + 1][vars->p_pos[1] / TSZ];
	if (c == 'C' || c == '0')
	{
		if (c == 'C')
			vars->o_items++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1], vars->p_pos[0]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1], vars->p_pos[0] + TSZ);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.player,
			vars->p_pos[1], vars->p_pos[0] + TSZ);
		vars->buffer[vars->p_pos[0] / TSZ][vars->p_pos[1] / TSZ] = '0';
		vars->p_pos[0] += 32;
		printf("Total moves: %d\n", vars->move_count++);
	}
	else if (c == 'E' && vars->o_items == vars->c_count)
		exit(ft_error(vars, 2));
}

void	left_move(t_gvars *vars)
{
	char	c;

	c = vars->buffer[vars->p_pos[0] / TSZ][vars->p_pos[1] / TSZ - 1];
	if (c == 'C' || c == '0')
	{
		if (c == 'C')
			vars->o_items++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1], vars->p_pos[0]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1] - TSZ, vars->p_pos[0]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.player,
			vars->p_pos[1] - TSZ, vars->p_pos[0]);
		vars->buffer[vars->p_pos[0] / TSZ][vars->p_pos[1] / TSZ] = '0';
		vars->p_pos[1] -= 32;
		printf("Total moves: %d\n", vars->move_count++);
	}
	else if (c == 'E' && vars->o_items == vars->c_count)
		exit(ft_error(vars, 2));
}

void	right_move(t_gvars *vars)
{
	char	c;

	c = vars->buffer[vars->p_pos[0] / TSZ][vars->p_pos[1] / TSZ + 1];
	if (c == 'C' || c == '0')
	{
		if (c == 'C')
			vars->o_items++;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1], vars->p_pos[0]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.floor,
			vars->p_pos[1] + TSZ, vars->p_pos[0]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.player,
			vars->p_pos[1] + TSZ, vars->p_pos[0]);
		vars->buffer[vars->p_pos[0] / TSZ][vars->p_pos[1] / TSZ] = '0';
		vars->p_pos[1] += 32;
		printf("Total moves: %d\n", vars->move_count++);
	}
	else if (c == 'E' && vars->o_items == vars->c_count)
		exit(ft_error(vars, 2));
}

int	key_hook_handle(int keycode, t_gvars *vars)
{
	if (keycode == 53)
		exit_hook(vars);
	else if (keycode == 0)
		left_move(vars);
	else if (keycode == 1)
		down_move(vars);
	else if (keycode == 13)
		up_move(vars);
	else if (keycode == 2)
		right_move(vars);
	return (0);
}