/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:20:05 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/31 17:28:25 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_offset(t_env *env, int keycode)
{
	if (keycode == 65361)
	{
		env->x_offset -= 0.2 * env->zoom;
		print_img(env);
	}
	if (keycode == 65362)
	{
		env->y_offset += 0.2 * env->zoom;
		print_img(env);
	}
	if (keycode == 65363)
	{
		env->x_offset += 0.2 * env->zoom;
		print_img(env);
	}
	if (keycode == 65364)
	{
		env->y_offset -= 0.2 * env->zoom;
		print_img(env);
	}
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		ft_exit(0, env);
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
		print_img(env);
	}
	else if (key == 5)
	{
		env->zoom *= 2;
		print_img(env);
	}
	return (0);
}

int	close_window(t_env *env)
{
	ft_exit(0, env);
	return (0);
}
