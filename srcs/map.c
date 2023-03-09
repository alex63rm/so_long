/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:20:27 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/09 21:23:34 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
Step 1. Create a file descriptor and open the file. The file name is argv[1],
which must be the name of a map: map_name.ber
Step 2. With the help of GNL, read the first line until \n or EOF (end of file)
Step 3. Keep reading in a loop until all the lines have been read. Return the
number of rows (or lines read)
*/
int	ft_map_height(char *str)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		//pending to check behaviour in iMac with valgrind
		//free(line);
		//line = NULL;
		line = get_next_line(fd);
		rows++;
	}
	//free(line);
	close(fd);
	return (rows);
}

char	**ft_map_fill(int columns, char *str)
{
	
}