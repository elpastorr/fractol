/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:31:32 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/23 17:48:31 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_env *env, int color)
{
	char	*dst;

	dst = env->data->addr + (env->y * env->data->line_length + env->x * (env->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_exit(int ret, t_env *env)
{
	if (env)
	{
		if (env->data)
			free(env->data);
		free(env);
	}
	exit(ret);
}

int close_window(t_env *env)
{
	ft_exit(0, env);
	return (0);
}

/*float	ft_abs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}*/

t_complex	conv(t_env *env)
{
	float	vx;
	float	vy;

	vx = (float)env->x;
	vy = (float)env->y;
	vx = (((vx - env->size_x / 2) / (env->size_x / 2)) * 2) * env->zoom + env->x_offset;
	vy = (((vy - env->size_y / 2) / (env->size_y / 2)) * 2) * -1 * env->zoom + env->y_offset;
	return (init_complex(vx, vy));
}

int	mandelbrot(t_complex c)
{
	int			i;
	t_complex	z;

	i = -1;
	z = init_complex(0, 0);
//	printf("vx = %f, vy = %f\n", c, vy);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(z), c);
	return(i);
}

void	put_color(int i, t_env *env)
{
	int	res;

	res = i % 16;
	if (i == 100)
		res = 0;
	else
		res = i * 1000;
	my_mlx_pixel_put(env, res);
}

void	print_img(t_env *env)
{
	env->x = -1;
	while (++env->x <= env->size_x)
	{
		env->y = -1;
		while (++env->y <= env->size_y)
			put_color(mandelbrot(conv(env)), env);
	}
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->data->img, 0, 0);
}

void	ft_offset(t_env *env, int keycode)
{
	printf("zoom = %f\n", env->zoom);
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
//	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		ft_exit(0, env);
	if (keycode >= 65361 && keycode <= 65364)
		ft_offset(env, keycode);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_env *env)
{
	printf("key : %d x = %d, y = %d\n", key, x, y);
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

void	init_env(t_env *env)
{
	env->data = malloc(sizeof(t_data));
	env->size_x = 1000;
	env->size_y = 1000;
	env->zoom = 1;
	env->x_offset = 0;
	env->y_offset = 0;
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, env->size_x, env->size_y, "EKIP");
	env->data->img = mlx_new_image(env->mlx, env->size_x, env->size_y);
	env->data->addr = (char *)mlx_get_data_addr(env->data->img, &env->data->bits_per_pixel, &env->data->line_length, &env->data->endian);
}

int	main()
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	init_env(env);
	print_img(env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1, close_window, env);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_loop(env->mlx);
	ft_exit(0, env);
}