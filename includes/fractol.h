/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:19:37 by elpastor          #+#    #+#             */
/*   Updated: 2022/04/07 17:07:41 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_complex {
	float	r;
	float	i;
}				t_complex;

typedef struct s_data {
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_env {
	t_data		*data;
	t_complex	comp;
	t_complex	jul_set;
	int			x;
	int			y;
	int			x_max;
	int			y_max;
	float		ratio;
	float		zoom;
	float		x_offset;
	float		y_offset;
	char		*set;
	int			colorset;
	void		*mlx;
	void		*mlx_win;
}				t_env;

t_complex	init_complex(float r, float i);
t_complex	square_complex(t_complex comp);
t_complex	add_complex(t_complex comp1, t_complex comp2);
float		complex_size(t_complex comp);
t_complex	abs_complex(t_complex comp);

void		ft_offset(t_env *env, int keycode);
int			key_hook(int keycode, t_env *env);
int			mouse_hook(int key, int x, int y, t_env *env);
int			close_window(t_env *env);

void		init_env(t_env *env, int ac, char **av);
void		ft_exit(int ret, t_env *env);
void		parsing(t_env *env);

void		my_mlx_pixel_put(t_env *env, int color);
t_env		*conv(t_env *env);
void		put_color(int i, t_env *env);
void		print_img(t_env *env, int (*f)(t_env *));

int			mandelbrot(t_env *env);
int			julia(t_env *env);
int			burn(t_env *env);

void		ft_putstr(char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *src);
int			ft_power(int nb, int power);
float		ft_atof(char *s, t_env *env);

#endif