/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:53:20 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/15 21:22:26 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
This function loops every position of the 2D map with a double loop
and counts the number of occurrences of char c
i is the counter of rows.
j is the counter of colums (i.e., positions in every row)
Loop the whole map at once until the final '\0'
*/
char	ft_get_object(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
/*
This function loops the copy of the map once it has been floodfilled. If it finds
an E or C it means that the exit or a collectible was not reachable and thus
calls the error function.
i is the counter of rows (Y)
j is the counter of colums (X)
*/
int	ft_check_floodfill(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
This is the floodfill standard algorithm. It is a recursive method that fills
an area when the conditions are met. In this case, it will stop when it is
outside the size of the map (redundant, since map is surrounded by '1') or when
the position is a wall '1'. Every time it visits a position, it marks it as
'V' (visited), which is also a condition to stop filling.
*/
void	ft_floodfill(char **map_copy, t_pos map_data, int x, int y)
{
	if (y >= map_data.size_y || x >= map_data.size_x || map_copy[y][x] == '1'
	|| map_copy[y][x] == 'V')
		return ;
	else
	{
		map_copy[y][x] = 'V';
		ft_floodfill(map_copy, map_data, x + 1, y);
		ft_floodfill(map_copy, map_data, x - 1, y);
		ft_floodfill(map_copy, map_data, x, y + 1);
		ft_floodfill(map_copy, map_data, x, y - 1);
	}
	return ;
}

/*
This function finds the initial position of the player and the size of
the map.
It just runs a regular loop, fixing the position of the current row y
and then loops all the positions of that row (columns x)
When it finds 'P' it saves the values of the player position in the struct
It continues reading all the map and then saves the size in the struct
*/
void	ft_find_p(char **map, t_pos *map_data)
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
			if (map[y][x] == 'P')
			{
				map_data->p_x = x;
				map_data->p_y = y;
			}
			x++;
		}
		y++;
	}
	map_data->size_y = y;
	map_data->size_x = x;
	return ;
}

/*
This function makes a copy of the map. It is an array of pointers,
each pointer points to a string. The logic is similar to ft_split
i is the counter of the first level of pointers (or number of rows)
j is an aux counter to loop and save all the lines

i = 0		| * |			*| 1 |	| 1 |	| 1 |
i = 1		| * |			*| 1 |	| 1 |	| 1 |
...			| * |			*| 1 |	| 1 |	| 1 |
i = n		| * |			*| 1 |	| 1 |	| 1 |

First, allocate memory for the array of pointers
Second, loop and duplicate all the lines of the map (arrays of chars)
Place NULL at the end of the array of pointers
*/
char	**ft_copy_map(char **map)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	while (map[i])
		i++;
	map_copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map_copy)
		return (0);
	j = 0;
	while (j < i)
	{
		map_copy[j] = ft_strdup(map[j]);
		j++;
	}
	map_copy[j] = NULL;
	return (map_copy);
}