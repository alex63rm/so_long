/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:10:34 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/11 13:58:55 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
This function will free all the memory and exit the program in error -1
Before exiting, it will free all the allocated memory
We need t_data *game to delete the original variable, not a local copy
*/
void	ft_error_exit(int type, t_data *game)
{
	if (type == WRONG_ARGS)
		printf("Wrong number of arguments. Just filepath is allowed\n");
	if (type == EMPTY_MAP)
		printf("Error. Map is empty\n");
	if (type == INVALID_MAP)
		printf("Error. Map must be a rectangle. Allowed chars: {0, 1, E, P, C}\n");

	(void)game;
	//free everything before exiting
	//ft_free_all()
	exit (-1);
}