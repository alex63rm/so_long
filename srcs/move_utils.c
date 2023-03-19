/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:12:20 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/19 14:50:20 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
This function prints the player after it has moved. Depending on the direction
it prints the corresponding XPM image. 
*/
int	ft_print_player(t_data *game, int *x, int *y, char direction)
{

}
/*
This function gets the position of the player in the map. It then updats the
coordinates in the map_data struct and copies them to the game struct
*/
void	ft_copy_p_pos(t_data *game, t_pos *map_data)
{
	game->p_x_copy = map_data->p_x;
	game->p_y_copy = map_data->p_y;
}

/*
Scans the map to check if there are still collectibles left
*/
int	ft_find_c(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
			{
				printf("collectible remaining");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}