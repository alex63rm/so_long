/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:03:57 by alejarod          #+#    #+#             */
/*   Updated: 2023/07/08 19:17:38 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function compares the len of the first line of the map against further
reads. If any line has different len than the first one, it means the map is
not rectangular. ft_strlen has been modified to stop reading when a '\n' or
'\0' (EOF) is found.
*/
static int	ft_map_isrectangle(char **map)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen_line(map[i]);
	if (line_len < 0)
		return (1);
	while (map[i])
	{
		if (ft_strlen_line(map[i]) != line_len)
			return (1);
		i++;
	}
	return (0);
}

/*
Checks if the map is surronunded by walls (char '1'). i is the counter for rows,
len is the counter for columns.
First part checks first and final columns.
		col 0					col len-1
row 0:	| 1 |					| 1 |
row 1:	| 1 |					| 1 |
...		| 1 |					| 1 |
...		| 1 |					| 1 |
row i:	| 1 |					| 1 |
After the first loop, the value i will be the number of rows
Second loop checks chars in the mid positions of first and last rows
row 0:			| 1 || 1 || 1 |
row 1:
...
...
row i:			| 1 || 1 || 1 |
*/
static int	ft_map_walls(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_line(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (1);
		i++;
	}
	while (len - 1 > 0)
	{
		if (map[0][len - 1] != '1' || map[i - 1][len - 1] != '1')
			return (1);
		len--;
	}
	return (0);
}

/*
This functions checks if there are 0 or more than one P or E in the map.
Several collectibles (C) are allowed
*/
static int	ft_object_iscorrect(char **map, char c)
{
	int	obj_count;

	obj_count = ft_get_object(map, c);
	if (obj_count == 0)
		return (1);
	if (obj_count > 1 && c != 'C')
		return (1);
	return (0);
}

/*
1. Create a copy of the map, in order not to modify the original map
2. Find the position of the player, it will be the start point
3. Floodfill algorithm in map_copy
4. Save the position of the player for later
Note that we send the address of the structure because it was created in 
this function
*/
static int	ft_path_iscorrect(t_data *game)
{
	char	**map_copy;
	t_pos	map_data;

	map_copy = ft_copy_map(game->map);
	ft_find_p(map_copy, &map_data);
	ft_floodfill(map_copy, map_data, map_data.p_x, map_data.p_y);
	if (ft_check_floodfill(map_copy) == 1)
	{
		ft_free_map(map_copy);
		return (1);
	}
	ft_copy_p_pos(game, &map_data);
	return (0);
}

/*
This function will check the different errors in the map
Function receives a pointer to make sure we are working on the original structure
and not in a local copy
Subject requirements:
Step 1. Map is not empty
Step 2. Map is a rectangle and must be surrounded by walls
Step 3. Check Player (P), Collectibles (C) and Exit (E)
Step 4. There must be a valid path to collect and exit
*/
int	ft_map_iserror(t_data *game)
{
	int	i;

	i = 0;
	if (game->map[i] == NULL)
		return (ft_error_exit(EMPTY_MAP, game), 1);
	if (ft_map_isrectangle(game->map) == 1)
		return (ft_error_exit(INVALID_MAP, game), 1);
	if (ft_map_walls(game->map) == 1)
		return (ft_error_exit(INVALID_WALLS, game), 1);
	if (ft_map_floor(game->map) == 1)
		return (ft_error_exit(INVALID_FLOOR, game), 1);
	if (ft_object_iscorrect(game->map, 'P') == 1 || \
		ft_object_iscorrect(game->map, 'E') \
		|| ft_object_iscorrect(game->map, 'C') == 1)
		return (ft_error_exit(INVALID_OBJECTS, game), 1);
	if (ft_path_iscorrect(game) == 1)
		return (ft_error_exit(INVALID_PATH, game), 1);
	return (0);
}
