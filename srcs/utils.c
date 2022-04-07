/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:54:09 by elpastor          #+#    #+#             */
/*   Updated: 2022/04/07 19:52:15 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (0);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

float	ft_atof(char *s, t_env *env)
{
	float	n;
	float	neg;
	int		i;
	int		exp;

	i = 0;
	n = 0;
	exp = 1;
	neg = 1;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		n = (n * 10) + (s[i++] - '0');
	if (s[i] != '.' && s[i])
		ft_exit(1, env);
	else if (!s[i])
		return (n * neg);
	while (s[++i] && s[i] >= '0' && s[i] <= '9')
		n += (float)(s[i] - '0') / (float)ft_power(10, exp++);
	if (s[i])
		ft_exit(1, env);
	return (n * neg);
}
