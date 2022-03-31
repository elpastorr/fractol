/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:19:54 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/31 18:33:17 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_env *env, int color)
{
	char	*dst;

	dst = env->data->addr + (env->y * env->data->line_length
			+ env->x * (env->data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_complex	conv(t_env *env)
{
	float	vx;
	float	vy;

	vx = env->x;
	vy = env->y;
	vx = ((vx / env->size_x) * 4 - 2) * env->zoom + env->x_offset;
	vy = -((vy / env->size_y) * 4 - 2) * env->zoom + env->y_offset;
	return (init_complex(vx, vy));
}

void	put_color(int i, t_env *env)
{
	int	res;

	res = i % 16;
	if (i == 100)
		res = 0;
	else
		res = i * 2000;//julia:150000 mandel:1000
	my_mlx_pixel_put(env, res);
}

void	print_img(t_env *env)
{
	env->x = -1;
	while (++env->x <= env->size_x)
	{
		env->y = -1;
		while (++env->y <= env->size_y)
			put_color(burn(conv(env)), env);
		//	put_color(julia(conv(env)), env);
		//	put_color(mandelbrot(conv(env)), env);
	}
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->data->img, 0, 0);
}
