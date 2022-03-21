#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		size_x;
	int		size_y;
	int		endian;
}				t_data;

#endif
