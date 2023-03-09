/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:53:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/10 00:32:59 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include"../mlx/mlx.h"
#include"printf.h"
#include"../ft_gnl/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
}	t_data;

void	ft_map_rows(t_data *game, char *str);
char	**ft_map_fill(int *rows, char *str);
int		ft_check_map(char **map);

#endif