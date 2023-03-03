/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:22:48 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/03 21:12:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<mlx.h>
#include<stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* establish a connection to the correct graphical system and will return a
void * which holds the location of our current MLX instance. */
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;		// is is a structure not a pointer like a linked list t_stack *stack_a;

	// step 1. Establish a connection to the screen
	mlx = mlx_init();	// establishes a connection to the screen, does not create the window
	// step 2. In that connection, open a window with a resolution and a title
	mlx_win = mlx_new_window(mlx, 640, 480, "hello world");	// returns a pointer to the window we created
	// step 3. In that connection, open the image. It is a void pointer as usual
	img.img = mlx_new_image(mlx, 640, 480);
	// step 4. Set the address of the image (second data inside the structure). We are required to dereference (pass the address)
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
/* 	Now we have the image address, but still no pixels. Before we start with this, we must understand that
	the bytes are not aligned, this means that the line_length differs from the actual window width. We therefore
	should ALWAYS calculate the memory offset using the line length set by mlx_get_data_addr. */
	// step 5. Now we now where to write the pixels and we can set the color ARGB (0, 255, 0, 0)

	// ESTA SI FUNCIONA
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	// NO ME FUNCIONAN (NO MUESTRA LAS LETRAS O EL PIXEL)
	mlx_string_put(mlx, mlx_win, 10, 10, 0x0000FF00, "HELLO");
	//mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);

/* 	Note that this will cause an issue. Because an image is represented in real time in a window,
	changing the same image will cause a bunch of screen-tearing when writing to it. You should therefore
	create two or more images to hold your frames temporarily. You can then write to a temporary image, so
	that you don’t have to write to the currently presented image. */
	// step 6. Push image to the window
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// step 7. loop to render the window constantly
	mlx_loop(mlx);
	//printf("%p", mlx_win);	// needed in linux to avoid gcc "unused variable" error
	//return (0);
}
