/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:10:34 by alejarod          #+#    #+#             */
/*   Updated: 2023/07/08 18:45:47 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function checks if the last 4 chars of the 1st argument
are .ber
*/
int	ft_check_extension(t_data *game, char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i])
		i++;
	len = i;
	if (str[len - 4] != '.' || str[len - 3] != 'b' || \
		str[len - 2] != 'e' || str[len - 1] != 'r')
	{
		ft_error_exit(WRONG_EXT, game);
		return (1);
	}
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (map[i] == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_gfree(t_data *game)
{
	if (game->map)
		ft_free_map(game->map);
	if (game->mlx)
		free(game->mlx);
}

int	ft_exit_ok(t_data *game)
{
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

/*
This function will free all the memory and exit the program in error -1
Before exiting, it will free all the allocated memory
We need t_data *game to delete the original variable, not a local copy.
There is a special case, if WRONG_ARGS, game was not created so no need to 
call ft_general_free()
*/
void	ft_error_exit(int type, t_data *game)
{
	if (type == WRONG_ARGS)
		return (ft_printf("Error\nWrong number of arguments\n"), exit(1));
	if (type == WRONG_EXT)
		return (ft_printf("Error\nInvalid mapn\n"), exit(1));
	if (type == EMPTY_MAP)
		return (ft_gfree(game), ft_printf("Error\nNo such file or map is \
		empty\n"), exit(1));
	if (type == INVALID_MAP)
		return (ft_gfree(game), ft_printf("Error\nMap must be a \
	rectangle.\n"), exit(1));
	if (type == INVALID_WALLS)
		return (ft_gfree(game), ft_printf("Error\nMap must be surrounded \
	by walls (wall char == '1')\n"), exit(1));
	if (type == INVALID_FLOOR)
		return (ft_gfree(game), ft_printf("Error\nFloor char must be '0'\n"), \
		exit(1));
	if (type == INVALID_OBJECTS)
		return (ft_gfree(game), ft_printf("Error\nInvalid object type or \
	number. Allowed types and count: P = 1, E = 1, C >= 1\n"), exit(1));
	if (type == INVALID_PATH)
		return (ft_gfree(game), ft_printf("Error\nInvalid path\n"), exit(1));
	if (type == INVALID_XPM)
		return (ft_gfree(game), ft_printf("Error\nXPM file not found\n"), \
	exit(1));
}
