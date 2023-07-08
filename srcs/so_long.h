/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:53:33 by alejarod          #+#    #+#             */
/*   Updated: 2023/07/08 11:13:40 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include"../mlx/mlx.h"
#include"../ft_printf/ft_printf.h"
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
#define MANUAL_CLOSE 107
#define WRONG_EXT 108
#define INVALID_FLOOR 109

//----------------------------XPM CONSTANTS-----------------------

#define WALL "textures/Wall.xpm"
#define FLOOR "textures/Floor.xpm"
#define COLLECT "textures/Collectible.xpm"
#define EXIT "textures/Exit.xpm"
#define PLAYER_U "textures/PlayerU.xpm"
#define PLAYER_D "textures/PlayerD.xpm"
#define PLAYER_L "textures/PlayerL.xpm"
#define PLAYER_R "textures/PlayerR.xpm"


typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	int		map_rows;
	int		p_x_copy;
	int		p_y_copy;
}	t_data;

typedef struct	s_pos
{
	int	p_x;
	int	p_y;
	int	size_x;
	int	size_y;
}	t_pos;

//--------------------MAIN FT----------------------

int		ft_check_extension(t_data *game, char *str);
void	ft_save_map(t_data *game, char *str);
char	**ft_map_fill(int *rows, char *str);
int		ft_map_iserror(t_data *game);
int		ft_error_exit(int type, t_data *game);
int		ft_exit_ok(t_data *game);
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
void	ft_copy_p_pos(t_data *game, t_pos *map_data);
int		ft_find_c(char **map);
char	*ft_player_look(char direction);
int		ft_print_player(t_data *game, int *x, int *y, char direction);




//temp functions
void	ft_print_map(t_data game);
void	ft_print_dup_map(char **map);

#endif