/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:53:20 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/14 13:36:48 by alejarod         ###   ########.fr       */
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