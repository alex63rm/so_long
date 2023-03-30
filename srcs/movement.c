/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:16:54 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/30 19:23:20 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function checks if all the collectibles have been collected. If so, the
final door opens. Notice that we have to check before entering the Door square,
else we enter the Door square and we would need one more movement to close
the program
*/
static void	ft_unlock_exit(t_data *game, int x, int y, char direction)
{
	if (direction == 'L' && game->map[y][x - 1] == 'E' &&
		ft_find_c(game->map) == 0)
			ft_exit_ok(game);
	if (direction == 'U' && game->map[y - 1][x] == 'E' &&
		ft_find_c(game->map) == 0)
			ft_exit_ok(game);
	if (direction == 'R' && game->map[y][x + 1] == 'E' &&
		ft_find_c(game->map) == 0)
			ft_exit_ok(game);
	if (direction == 'D' && game->map[y + 1][x] == 'E' &&
		ft_find_c(game->map) == 0)
			ft_exit_ok(game);
}

/*
This function updates the player position with the help of the mlx library. It
will replace the player position with an empty (FLOOR) image. Then it will print
the player again in the new position.
Notice that x and y received is an address. We are using the content with *x
and *y, and then sending the address to ft_print_player.
Finally, if the player moved to a tile with a C, it will be replaced by 0, to
count the remaining collectibles and unlock the final exit tile.
*/
static void	ft_move_player(t_data *game, int *x, int *y, char direction)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, FLOOR, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->window, img, (*x * 80), (*y * 80));
	ft_print_player(game, x, y, direction);
	if (game->map[*y][*x] == 'C')
		game->map[*y][*x] = '0';
}

/*
This function checks if the player reached a wall. Checks every direction
related to the key pressed and returns 0 or 1 depending on wheather the
movement was possible or not
*/
static int	ft_player_stop(t_data *game, int x, int y, char direction)
{
	if (direction == 'L')
	{
		if (game->map[y][x - 1] == '1' || (game->map[y][x - 1] == 'E'
		&& ft_find_c(game->map) != 0))
		
			return (1);
	}
	if (direction == 'U')
	{
		if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E'
		&& ft_find_c(game->map) != 0))
			return (1);
	}
	if (direction == 'R')
	{
		if (game->map[y][x + 1] == '1' || (game->map[y][x + 1] == 'E'
		&& ft_find_c(game->map) != 0))
			return (1);
	}
	if (direction == 'D')
	{
		if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E'
		&& ft_find_c(game->map) != 0))
			return (1);
	}
	return (0);
}
/*
This function gets the initial position of the player the first time it runs.
Step 1. Check if the player moved or not and returns if it did not.
Step 2. Check if the player reached the exit
Step 3. If it did not, move the player
*/
static int	ft_move(t_data *game, char direction)
{
	static int	x;
	static int	y;

	if (!x && !y)
	{
		y = game->p_y_copy;
		x = game->p_x_copy;
	}
	if (ft_player_stop(game, x, y, direction) == 1)
		return (0);
	ft_unlock_exit(game, x, y, direction);
	ft_move_player(game, &x, &y, direction);
	ft_printf("updated player ROW (y) after move is: |%d|\n", y);
	ft_printf("updated player COLUMN (x) after move is: |%d|\n\n", x);
	return (1);
}

/*
This function records the keys pressed and moves the character.
Static variables are variables that retain their value between function calls,
so the first time the function is called, i is initialized to 0 and
subsequent calls will retain the previous value of i.
key codes correspond to specific keys on the keyboard, and they are usually
defined by the operating system.
Linux-Ubuntu
65361: left / 65362 up / 65363 right / 65364 down / 65307 ESC
The move flag determines if the player moved, by receiving a value from
ft_move, if so, it increases tha variable i.
*/
int	ft_input(int key, t_data *game)
{
	static int	i;
	int			move_flag;

	if (!i)
		i = 0;
	move_flag = 1;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 53)
	{
		if (key == 53)
		 	ft_exit_ok(game);
		if (key == 123)
			move_flag = ft_move(game, 'L');
		if (key == 124)
			move_flag = ft_move(game, 'R');
		if (key == 125)
			move_flag = ft_move(game, 'D');
		if (key == 126)
			move_flag = ft_move(game, 'U');
		if (move_flag == 1)
		{
			i++;
			ft_printf("Movement #: |%d| -> key pressed |%d|\n", i, key);
		}
	}
	return (0);
}