/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:31:32 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/31 18:23:05 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(int ret, t_env *env)
{
	mlx_destroy_window(env->mlx, env->mlx_win);
	if (env)
	{
		if (env->data)
		{
			mlx_destroy_image(env->mlx, env->data->img);
			free(env->data);
		}
		free(env);
	}
	exit(ret);
}

int	mandelbrot(t_complex c)
{
	int			i;
	t_complex	z;

	i = -1;
	z = init_complex(0, 0);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(z), c);
	return (i);
}

int	julia(t_complex z)
{
	int			i;
	t_complex	c;

	i = -1;
	c = init_complex(0.285, 0.01);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(z), c);
	return (i);
}

float	ft_abs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	burn(t_complex c)
{
	int			i;
	t_complex	z;

	i = -1;
	z = init_complex(0, 0);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(init_complex(ft_abs(z.r), ft_abs(z.i))), c);
	return (i);
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
	env->data->addr = (char *)mlx_get_data_addr(env->data->img, &env->data->bpp,
			&env->data->line_length, &env->data->endian);
}

int	main(int ac, char **av)
{
	t_env	*env;

	(void)ac;
	(void)av;
	env = malloc(sizeof(t_env));
	init_env(env);
	print_img(env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1, close_window, env);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_loop(env->mlx);
	ft_exit(0, env);
}
