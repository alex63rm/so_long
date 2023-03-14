/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:53:20 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/14 22:25:04 by alejarod         ###   ########.fr       */
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