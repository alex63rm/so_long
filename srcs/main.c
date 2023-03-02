/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:22:48 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/02 21:46:29 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include<stdio.h>

/* typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
 */
/* establish a connection to the correct graphical system and will return a
void * which holds the location of our current MLX instance. */
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	//t_data	*img;	//

	mlx = mlx_init();	// this initiates the screen
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world");	// returns a pointer to the window we created
	mlx_loop(mlx);	// loop to render the window constantly
	//img = mlx_new_image(mlx, 1920, 1080);
	printf("%p", mlx_win);	// needed in liunux to avoid a gcc error
}