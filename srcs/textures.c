/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:12:39 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/17 21:10:02 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*
This function uses the mlx library functions to convert the xpm file
to an image. mlx variable, pathfile, image width and height are required
Remember 3 things: first start mlx, then window, then img over window.
*/
static void	ft_put_image(t_data *game, char *c, int x, int y)
{
	void	*img;
	int		img_w;
	int		img_h;

	img = mlx_xpm_file_to_image(game->mlx, c, &img_w, &img_h);
	if (!img)
		ft_error_exit(INVALID_XPM, game);
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

/*
The function searches for the char in order to load the corresponding
image. The path is a constant define in the header file.
*/
static void	ft_load_texture(t_data *game, char c, int x, int y)
{
	if (c == '0')
		ft_put_image(game, FLOOR, x, y);
	if (c == '1')
		ft_put_image(game, WALL, x, y);
	if (c == 'P')
		ft_put_image(game, PLAYER_D, x, y);
	if (c == 'C')
		ft_put_image(game, COLLECT, x, y);
	if (c == 'E')
		ft_put_image(game, EXIT, x, y);

}

/*
This function scans the map with a double loop, using i and j as counters.
It sends the found char variable (as well as the coordinates x and y that
determine the position of that char) to the function ft_load_texture.
*/
void	ft_scan_map(t_data *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		x = 0;
		j = 0;
		while (game->map[i][j] != '\0')
		{
			ft_load_texture(game, game->map[i][j], x, y);
			x = x + 80;
			j++;
		}
		y = y + 80;
		i++;
	}

}