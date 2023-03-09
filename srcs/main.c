/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:51 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/09 21:25:07 by alejarod         ###   ########.fr       */
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
		game.height = ft_map_height(argv[1]);
		// game.map = ft_matrix(game.width, argv[1]);
		// if (ft_check_map(game.map))
		// {
		// 	ft_free(game.map);
		// 	return (0);
		// }
		// ft_load_map(&game);
	}
	printf("rows: %d\n", game.height);
	return (0);
}