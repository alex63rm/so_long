/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:51 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/10 00:38:00 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


/* The program starts here.
Step 1. Check the the length of one line of the given map. It is rectangular, so
all the lines will be the same lenght
Step 2. Load the map with ft_matrix
Step 3. Check tghat the map does not contain errors
Step 4. If everything is correct, load the map.
of the map to make it full screen in the window.
*/
int	main(int argc, char **argv)
{
	t_data	game;

	if (argc == 2)
	{
		ft_map_rows(&game, argv[1]);
		// if (ft_check_map(game.map))
		// {
		// 	ft_free(game.map);
		// 	return (0);
		// }
		// ft_load_map(&game);
	}
	// JUST PRINT TEST
	int i = 0;
	while (game.map[i])
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	// JUST PRINT TEST
	return (0);
}