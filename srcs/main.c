/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:51 by alejarod          #+#    #+#             */
/*   Updated: 2023/07/08 18:47:07 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_struct(t_data *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->map_rows = 0;
	game->p_x_copy = 0;
	game->p_y_copy = 0;
	game->final_move = 0;
}

/*
This function starts the game by using some defined functions from the
mlx library.
Step 1. Init the mlx.
Step 2. Load a window.
Step 3. Scan the map and load the images over the window
Step 4. Mlx_key_hook requires mlx, a function that defines the input and
the parameters, which in our case is a structure
Step 5. mlx_hook registers an event and a mask that is defined in the
library documentation.
*/
static void	ft_init_game(t_data *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (ft_strlen_line(game->map[0]) \
	* 80), ((game->map_rows) * 80), "Forest Adventure");
	ft_scan_map(game);
	mlx_key_hook(game->window, *ft_input, game);
	mlx_hook(game->window, 17, 1L << 17, ft_exit_ok, game);
	mlx_loop(game->mlx);
}

/* The program starts here.
Step 1. Check the number of rows in the map and save it in the map
variable inside of the structure
Step 2. Check that the map does not contain errors
Step 4. If everything is correct, initialize the game.
of the map to make it full screen in the window.
*/
int	main(int argc, char **argv)
{
	t_data	game;

	if (argc == 2)
	{
		ft_init_struct(&game);
		if (ft_check_extension(&game, argv[1]) == 1)
			return (1);
		ft_save_map(&game, argv[1]);
		if (ft_map_iserror(&game) == 1)
			return (1);
		ft_init_game(&game);
	}
	ft_error_exit(WRONG_ARGS, &game);
	return (0);
}
