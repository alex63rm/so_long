/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_temp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:42:12 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/30 21:02:58 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_data game)
{
	int i = 0;
	while (game.map[i])
	{
		ft_printf("%s", game.map[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_print_dup_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}
