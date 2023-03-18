/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:16:54 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/18 14:30:06 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function records the keys pressed and moves the character.
Static variables are variables that retain their value between function calls,
so the first time the function is called, i is initialized to 0 and
subsequent calls will retain the previous value of i.
key codes correspond to specific keys on the keyboard, and they are usually
defined by the operating system.
macOS:
123: left arrow, 124: right, 125: down, 126: up. 53: ESC
Linux-Ubuntu

*/
int	ft_input(int key, t_data *game)
{
	static int	i;
	int			check_move;

	if (!i)
		i = 0;
	check_move = 0;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 53)
	{
		if (key == 53)
		 	ft_exit_ok(game);
		if (key == 123)
			//AQUI!!!!!

		if (check_move == 0)
			printf("Movement #: |%d|\n, key pressed |%d|", i++, key);
	}
	//temp
	if (check_move == 0)
		printf("Movement #: |%d|, key pressed |%d|\n", i++, key);
	//temp
	return (0);
}