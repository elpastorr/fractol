/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:03:43 by elpastor          #+#    #+#             */
/*   Updated: 2022/04/07 17:05:02 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_env *env)
{
	int			i;
	t_complex	c;
	t_complex	z;

	i = -1;
	c = env->comp;
	z = init_complex(0, 0);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(z), c);
	return (i);
}

int	julia(t_env *env)
{
	int			i;
	t_complex	c;
	t_complex	z;

	i = -1;
	z = env->comp;
	c = init_complex(env->jul_set.r, env->jul_set.i);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(z), c);
	return (i);
}

int	burn(t_env *env)
{
	int			i;
	t_complex	c;
	t_complex	z;

	c = env->comp;
	c.i = -c.i;
	i = -1;
	z = init_complex(0, 0);
	while (++i < 100 && complex_size(z) < 4)
		z = add_complex(square_complex(abs_complex(z)), c);
	return (i);
}
