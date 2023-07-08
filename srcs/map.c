/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:20:27 by alejarod          #+#    #+#             */
/*   Updated: 2023/07/08 19:14:50 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
Calculate the number of rows to create the map
1. Open the file to a fd. Name is the argv[1] which must be a .ber file
2. Read line by line with GNL
3. Loop until all the lines have been read.
4. Save the number of rows
5. Save the map data in a map variable inside the structure
*/
void	ft_save_map(t_data *game, char *str)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		rows++;
	}
	free(line);
	game->map_rows = rows;
	game->map = ft_map_fill(&rows, str);
}

/*
This function starts to write the map line by line. It will also add the '\0'
as the final char of the string.
Step 1. Allocate memory for the map with malloc. It is a two dimensional array.
So, we need to add a '\0' at the end of each row and also at the end of the array
of pointers (similar to ft_split)
Step 2. Create the loop and load each line into the map. In the last position of
the line add the '\0' char. After exiting the loop, add the '\0' to the array
of pointers.
*/
char	**ft_map_fill(int *rows, char *str)
{
	char	**map;
	int		i;
	int		line_len;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (*rows + 1));
	if (!map)
		return (0);
	while (i < *rows)
	{
		map[i] = get_next_line(fd);
		line_len = ft_strlen(map[i]);
		map[i][line_len] = '\0';
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

/* This function returns 1 as error if the floor is not a '0', as required
by the subject. It loops all the positions within the wall. If it finds a
char that is not allowed, the function returns 1 as error.
*/
int	ft_map_floor(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'E' \
			|| map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
