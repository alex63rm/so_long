/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:51 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/09 00:16:44 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


int	main(int argc, char **argv)
{
	t_data	game;

	if (argc == 2)
	{
		game.width = ft_map_lines(argv[1]);			// sets the width of the screen
		game.map = ft_matrix(game.width, argv[1]);	// loads the map
		if (ft_check_map(game.map))
		{
			ft_free(game.map);
			return (0);
		}
		ft_load_map(&game);
	}
	return (0);
}