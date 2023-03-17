/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:12:39 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/17 19:38:05 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	ft_load_texture(t_data *game, char c, int x, int y);
{
	
}

/*
This function scans the map with a double loop, using i and j as counters.
It sends the found char variable (as well as the coordinates x and y that
determine the position of that char) to the function ft_load_texture.
*/
void	ft_scan_map(t_data *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		x = 0;
		j = 0;
		while (game->map[i][j] != '\0')
		{
			ft_load_texture(game, game->map[i][j], x, y);
			x = x + 80;
			j++;
		}
		y = y + 80;
		i++;
	}

}