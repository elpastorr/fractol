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

/*int	main(int ac, char **av)
{
	t_complex	*oui;

	oui = malloc(sizeof(t_complex));
	oui.x = 1.2142;
	oui.y = 2.1222;
	printf("comp = %f + %fi\n", oui.x, oui.y);
	printf("aled\n");
	oui = square_complex(oui);
	printf("aled\n");
	printf("comp = %f + %fi\n", oui.x, oui.y);
}

t_complex	multiply_complex(t_complex comp1, t_complex comp2)
{
	t_complex	*new_comp;

	new_comp.x = (comp1.x * comp2.x) - (comp1.y * comp2.y);
	new_comp.y = (comp1.x * comp2.y) + (comp1.y * comp2.x);

}*/
