/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:51 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/15 22:16:16 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
This function returns the length of a line up to the '\n', i.e, the lenght
of the first line of the map
*/
int	ft_strlen_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

/*
This function starts the game by using some defined functions from the
mlx library

*/
static void	ft_init_game(t_data *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (ft_strlen_line(game->map[0]) * 80),
	((game->map_rows) * 80), "My_title");
	ft_draw_map(game);

	// SEGUIR AQUI
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
		ft_save_map(&game, argv[1]);
		ft_map_iserror(&game);

	// JUST PRINT TEST
		printf("map is correct. map is:\n");
		ft_print_map(game);
	// JUST PRINT TEST

		ft_init_game(&game);
	}
	else
		ft_error_exit(WRONG_ARGS, &game);
	printf("exit status 0\n");
	return (0);
}