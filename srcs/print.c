/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:19:54 by elpastor          #+#    #+#             */
/*   Updated: 2022/04/07 16:57:01 by elpastor         ###   ########.fr       */
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

t_env	*conv(t_env *env)
{
	float	vx;
	float	vy;

	vx = env->x;
	vy = env->y;
	vx = (((vx / env->x_max) * 4 - 2) * env->zoom + env->x_offset) * env->ratio;
	vy = (-((vy / env->y_max) * 4 - 2) * env->zoom + env->y_offset);
	env->comp = init_complex(vx, vy);
	return (env);
}

void	put_color(int i, t_env *env)
{
	int	res;

	res = i % 16;
	if (i == 100)
		res = 0;
	else
		res = i * env->colorset;
	my_mlx_pixel_put(env, res);
}

void	print_img(t_env *env, int (*f)(t_env *))
{
	env->x = -1;
	while (++env->x <= env->x_max - 1)
	{
		env->y = -1;
		while (++env->y <= env->y_max - 1)
			put_color((*f)(conv(env)), env);
	}
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->data->img, 0, 0);
}
