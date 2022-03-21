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
	int 	size_x;
	int		size_y;
}				t_data;

typedef struct	s_complex {
	float	r;
	float	i;
}				t_complex;

t_complex	square_complex(t_complex comp);
t_complex	add_complex(t_complex comp1, t_complex comp2);

#endif
