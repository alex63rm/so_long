/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:20:27 by alejarod          #+#    #+#             */
/*   Updated: 2023/07/08 17:02:17 by alejarod         ###   ########.fr       */
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
This function calculates the number of rows as the first step to create the map
Step 1. Create a file descriptor and open the file. The file name is argv[1],
which must be the name of a map: map_name.ber
Step 2. With the help of GNL, read the first line until \n or EOF (end of file)
Step 3. Keep reading in a loop until all the lines have been read. I decided
to pass the address of rows to the next function to practice pointers.
Step 4. Save the number of rows, it will be used later to open the game window
Step 5. Call map_fill to save the map data in map variable inside of the structure
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
