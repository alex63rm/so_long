/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:53:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/09 21:19:36 by alejarod         ###   ########.fr       */
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
	int		height;
}	t_data;

int		ft_map_height(char *str);
char	**ft_matrix(int width, char *str);
int		ft_check_map(char **map);

#endif