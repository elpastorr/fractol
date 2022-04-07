/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:20:05 by elpastor          #+#    #+#             */
/*   Updated: 2022/04/07 19:50:13 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_offset(t_env *env, int keycode)
{
	if (keycode == 65361)
		env->x_offset -= 0.2 * env->zoom;
	else if (keycode == 65362)
		env->y_offset += 0.2 * env->zoom;
	else if (keycode == 65363)
		env->x_offset += 0.2 * env->zoom;
	else if (keycode == 65364)
		env->y_offset -= 0.2 * env->zoom;
	parsing(env);
}

void	color_shift(t_env *env)
{
	if (env->colorset < 280000000)
		env->colorset *= 3;
	else
		env->colorset = 1000;
	parsing(env);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		ft_exit(0, env);
	if (keycode == 32)
		color_shift(env);
	if (keycode >= 65361 && keycode <= 65364)
		ft_offset(env, keycode);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		env->zoom /= 2;
		parsing(env);
	}
	else if (key == 5)
	{
		env->zoom *= 2;
		parsing(env);
	}
	return (0);
}

int	close_window(t_env *env)
{
	ft_exit(0, env);
	return (0);
}
