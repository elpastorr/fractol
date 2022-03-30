#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_complex {
	float	r;
	float	i;
}				t_complex;

typedef	struct	s_env {
	t_data		*data;
	t_complex	*comp;
	int			x;
	int			y;
	int 		size_x;
	int			size_y;
	float		zoom;
	float		x_offset;
	float		y_offset;
	void		*mlx;
	void		*mlx_win;
}				t_env;

t_complex	init_complex(float r, float i);
t_complex	square_complex(t_complex comp);
t_complex	add_complex(t_complex comp1, t_complex comp2);
float		complex_size(t_complex comp);

#endif