/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:31:32 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/21 18:47:25 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_exit(int ret)
{
	exit(ret);
}

int	key_hook(int keycode, t_data *img)
{
	(void)img;
	if (keycode == 65307)
		ft_exit(0);
	return (0);
}

int	ft_init(t_data *img)
{
	img->size_x = 1000;
	img->size_y = 1000;
	return (0);
}

int	mouse_hook(int key, int x, int y, t_data *img)
{
	return (0);
}

t_complex	init_complex(float r, float i)
{
	t_complex	new_complex;

	new_complex.r = r;
	new_complex.i = i;
	return (new_complex);
}

t_complex	conv(float x, float y, t_data *img)
{
	float	vx;
	float	vy;

	vx = (((x - img->size_x / 2) / (img->size_x / 2)) * 2);
	vy = (((y - img->size_y / 2) / (img->size_y / 2)) * 2) * -1;
	return (init_complex(vx, vy));
}

float	complex_size(t_complex comp)
{
	return (comp.r * comp.r + comp.i * comp.i);
}

int	mandelbrot(t_complex c)
{
	int			i;
	t_complex	z;

	i = -1;
	z = init_complex(0, 0);
	printf("x = %f, y = %f\n", c.r, c.i);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(z), c);
	return (i);

}

/*char	*get_color()
{
	return (0);
}*/

int	main()
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_data	*img;

	x = -1;
	img = malloc(sizeof(t_data));
	mlx = mlx_init();
	ft_init(img);
	mlx_win = mlx_new_window(mlx, img->size_x, img->size_y, "EKIP");
	img->img = mlx_new_image(mlx, img->size_x, img->size_y);
	img->addr = (char *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	
	while (++x <= img->size_x)
	{
		y = -1;
		while (++y <= img->size_y)
		{
			
/*			if (!mandelbrot(conv((float)x, (float)y, img)))
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			else	
				my_mlx_pixel_put(img, x, y, 0x00000000);*/
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
//	mlx_mouse_hook(mlx_win, mouse_hook, img);
//	mlx_key_hook(mlx_win, key_hook, img);
	mlx_loop(mlx);
}
