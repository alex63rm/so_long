/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:51 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/11 13:43:54 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


/* The program starts here.
Step 1. Check the number of rows in the map and save it in the map
variable inside of the structure
Step 2. Check that the map does not contain errors
Step 4. If everything is correct, load the map.
of the map to make it full screen in the window.
*/
int	main(int argc, char **argv)
{
	t_data	game;

	if (argc == 2)
	{
		ft_save_map(&game, argv[1]);
		ft_map_iserror(&game);

		ft_print_map(game);
		printf("\n");	// additional \n at the end of the map
		// ft_load_map(&game);
	}
	// JUST PRINT TEST
	// JUST PRINT TEST
	else
		ft_error_exit(WRONG_ARGS, &game);
	printf("exit status 0\n");
	return (0);
}