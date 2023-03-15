/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:10:34 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/15 21:42:27 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (map[i] == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);

}

/*
This function will free all the memory and exit the program in error -1
Before exiting, it will free all the allocated memory
We need t_data *game to delete the original variable, not a local copy
*/
void	ft_error_exit(int type, t_data *game)
{
	if (type == WRONG_ARGS)
		printf("Error\nWrong number of arguments. Just filepath is allowed\n");
	if (type == EMPTY_MAP)
		printf("Error\nMap is empty\n");
	if (type == INVALID_MAP)
		printf("Error\nMap must be a rectangle.\n");
	if (type == INVALID_WALLS)
		printf("Error\nMap must be surrounded by walls (wall char == '1')\n");
	if (type == INVALID_OBJECTS)
		printf("Error\nInvalid object type or number. Allowed types and count: P = 1, E = 1, C >= 1\n");
	if (type == INVALID_PATH)
		printf("Error\nPlayer is unable to collect all objects and reach the exit\n");

	//free everything before exiting
	// free get next line etc
	ft_free_map(game->map);
	//static void	ft_free_all(t_data *game)
	//
	exit (-1);
}