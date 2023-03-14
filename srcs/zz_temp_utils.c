/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:42:12 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/14 22:34:24 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_data game)
{
	int i = 0;
	while (game.map[i])
	{
		printf("%s", game.map[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_dup_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}
