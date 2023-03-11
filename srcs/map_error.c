/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:03:57 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/11 14:02:19 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
/*
This function checks all the possible errors in the map set by the subject
Step 1. Check that the map is not empty
Step 2. Check that the map is a rectangle and that it is surrounded by walls
Step 3. Check players, collectibles and exit
Step 4. Check that it is possible to collect the objects and reach the exit

*/

// static int	ft_path_iscorrect(char **map)
// {
// 	(void)map;
// 	return (0);
// }

static int	ft_map_isrectangle(char **map)
{
	(void)map;
	///SEGURI AQUI
	return (0);
}

/*
This function will check the different errors in the map
We send the pointer to make sure we are working on the original structure
and not in a local copy
*/

void	ft_map_iserror(t_data *game)
{
	printf("entered ft_map_iserror\n");
	int	i;

	i = 0;
	if (game->map[i] == NULL)
		ft_error_exit(EMPTY_MAP, game);
	if (ft_map_isrectangle(game->map) == 1)
	 	ft_error_exit(INVALID_MAP, game);
	//if (ft_path_iscorrect(game->map) == 1)

	//(void)map;

}