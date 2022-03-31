/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:19:59 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/31 17:25:51 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	complex_size(t_complex comp)
{
	return (comp.r * comp.r + comp.i * comp.i);
}

t_complex	init_complex(float r, float i)
{
	t_complex	new_complex;

	new_complex.r = r;
	new_complex.i = i;
	return (new_complex);
}

t_complex	add_complex(t_complex comp1, t_complex comp2)
{
	t_complex	result;

	result.r = comp1.r + comp2.r;
	result.i = comp1.i + comp2.i;
	return (result);
}

t_complex	square_complex(t_complex comp)
{
	t_complex	result;

	result.r = (comp.r * comp.r) - (comp.i * comp.i);
	result.i = 2 * comp.r * comp.i;
	return (result);
}
