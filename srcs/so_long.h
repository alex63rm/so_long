/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:53:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/17 21:29:28 by alejarod         ###   ########.fr       */
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
#define INVALID_XPM 106

//----------------------------XPM CONSTANTS-----------------------

#define FLOOR "textures/floor.xpm"
#define WALL "textures/wall.xpm"
#define COLLECT "textures/collectible.xpm"
#define EXIT "textures/exit.xpm"
#define PLAYER_U "textures/playerU.xpm"
#define PLAYER_D "textures/playerD.xpm"
#define PLAYER_L "textures/playerL.xpm"
#define PLAYER_R "textures/playerR.xpm"


typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	int		map_rows;
}	t_data;

typedef struct	s_pos
{
	int	p_x;
	int	p_y;
	int	size_x;
	int	size_y;
}	t_pos;

//--------------------MAIN FT----------------------
void	ft_save_map(t_data *game, char *str);
char	**ft_map_fill(int *rows, char *str);
void	ft_map_iserror(t_data *game);
void	ft_error_exit(int type, t_data *game);
void	ft_free_map(char **map);
void	ft_scan_map(t_data *game);
int		ft_input(int key, t_data *game);


//--------------------UTILS----------------------
int		ft_strlen_line(char *str);
char	ft_get_object(char **map, char c);
char	**ft_copy_map(char **map);
void	ft_find_p(char **map, t_pos *player);
void	ft_floodfill(char **map_copy, t_pos map_data, int x, int y);
int		ft_check_floodfill(char **map_copy);



//temp functions
void	ft_print_map(t_data game);
void	ft_print_dup_map(char **map);

#endif