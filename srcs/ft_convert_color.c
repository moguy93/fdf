/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:21:52 by moguy             #+#    #+#             */
/*   Updated: 2019/04/29 13:56:12 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_choice(int i, int n, char *color)
{
	if (color[i] >= '0' && color[i] <= '9')
		return (ft_power(16, n) * (color[i] - '0'));
	else if (color[i] == 'A' || color[i] == 'a')
		return (ft_power(16, n) * 10);
	else if (color[i] == 'B' || color[i] == 'b')
		return (ft_power(16, n) * 11);
	else if (color[i] == 'C' || color[i] == 'c')
		return (ft_power(16, n) * 12);
	else if (color[i] == 'D' || color[i] == 'd')
		return (ft_power(16, n) * 13);
	else if (color[i] == 'E' || color[i] == 'e')
		return (ft_power(16, n) * 14);
	else if (color[i] == 'F' || color[i] == 'f')
		return (ft_power(16, n) * 15);
	return (0);
}

int			ft_convert_color(char *color)
{
	int		ret;
	int		n;
	int		i;

	ret = 0;
	n = 0;
	i = 0;
	while (color[i] != '\0')
		i++;
	while (--i >= 0)
	{
		ret = ret + ft_choice(i, n, color);
		n++;
	}
	return (ret);
}
