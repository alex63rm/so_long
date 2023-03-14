/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:53:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/14 22:26:41 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include"../mlx/mlx.h"
#include"printf.h"
#include"../ft_gnl/get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

//----------------------------ERROR TYPES-------------------------

#define	WRONG_ARGS 100
#define	EMPTY_MAP 101
#define	INVALID_MAP 102
#define	INVALID_WALLS 103
#define	INVALID_OBJECTS 104
#define	INVALID_PATH 105


typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
}	t_data;

void	ft_save_map(t_data *game, char *str);
char	**ft_map_fill(int *rows, char *str);
void	ft_map_iserror(t_data *game);
void	ft_error_exit(int type, t_data *game);

//--------------------UTILS----------------------
int		ft_strlen_line(char *str);
char	ft_get_object(char **map, char c);
char	**ft_copy_map(char **map);


//temp functions
void	ft_print_map(t_data game);
void	ft_print_dup_map(char **map);

#endif