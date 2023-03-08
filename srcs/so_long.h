/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:53:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/09 00:07:05 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include"../mlx/mlx.h"
#include"printf.h"
#include"../ft_gnl/get_next_line.h"
#include<stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	int		width;	// it is going to hold the lenght of the map line
}	t_data;


#endif