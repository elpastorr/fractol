/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:31:32 by elpastor          #+#    #+#             */
/*   Updated: 2022/04/07 18:18:22 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(int ret, t_env *env)
{
	if (env->mlx_win)
		mlx_destroy_window(env->mlx, env->mlx_win);
	if (env)
	{
		if (env->data)
		{
			mlx_destroy_image(env->mlx, env->data->img);
			free(env->data);
		}
		if (env->set)
			free(env->set);
		if (env->mlx)
			free(env->mlx);
		free(env);
	}
	exit(ret);
}

void	print_exit(t_env *env)
{
	ft_putstr("Parametre non valide;\nIndiquer quel ensemble vous voulez :");
	ft_putstr("\nMandelbrot : mandel\nJulia : jul\nBuring Ship : burn\n");
	ft_exit(1, env);
}

void	init_env(t_env *env, int ac, char **av)
{
	env->data = malloc(sizeof(t_data));
	env->x_max = 1000;
	env->y_max = 1000;
	env->ratio = (float)env->x_max / (float)env->y_max;
	env->zoom = 1;
	env->x_offset = 0;
	env->y_offset = 0;
	if (ac > 1)
		env->set = ft_strdup(av[1]);
	else
		env->set = ft_strdup("");
	if (ac > 3)
		env->jul_set = init_complex(ft_atof(av[2], env), ft_atof(av[3], env));
	else
		env->jul_set = init_complex(0.285, 0.01);
	env->colorset = 1000;
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, env->x_max, env->y_max, "EKIP");
	env->data->img = mlx_new_image(env->mlx, env->x_max, env->y_max);
	env->data->addr = (char *)mlx_get_data_addr(env->data->img, &env->data->bpp,
			&env->data->line_length, &env->data->endian);
}

void	parsing(t_env *env)
{
	if (ft_strcmp(env->set, "mandel") == 0)
		print_img(env, &mandelbrot);
	else if (ft_strcmp(env->set, "jul") == 0)
	{
		env->colorset = 150000;
		print_img(env, &julia);
	}
	else if (ft_strcmp(env->set, "burn") == 0)
		print_img(env, &burn);
	else
		print_exit(env);
}

int	main(int ac, char **av)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	init_env(env, ac, av);
	if (ac < 2)
		print_exit(env);
	parsing(env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1, close_window, env);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_loop(env->mlx);
}
