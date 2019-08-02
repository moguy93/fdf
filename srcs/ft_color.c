/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 08:22:46 by moguy             #+#    #+#             */
/*   Updated: 2019/01/28 04:40:08 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_change_white(t_map **map, t_map **tmp, t_size *size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size->size_c)
	{
		x = 0;
		while (x < size->size_l)
		{
			map[y][x].color = 16777215;
			tmp[y][x].color = 16777215;
			x++;
		}
		y++;
	}
}

void	ft_change_red(t_map **map, t_map **tmp, t_size *size)
{
	int		x;
	int		y;
	double	h;

	y = 0;
	size->hmin = ft_abs(size->hmin);
	size->hmax = (size->hmax > size->hmin) ? size->hmax : size->hmin;
	while (y < size->size_c)
	{
		x = 0;
		while (x < size->size_l)
		{
			h = (map[y][x].heigth > 0) ? (double)map[y][x].heigth /
			(double)size->hmax : (double)-map[y][x].heigth / (double)size->hmax;
			map[y][x].color = ((int)(h * 200) * 256) + 14080 + 255;
			tmp[y][x].color = map[y][x].color;
			x++;
		}
		y++;
	}
}

void	ft_change_green(t_map **map, t_map **tmp, t_size *size)
{
	int		x;
	int		y;
	double	h;

	y = 0;
	size->hmin = ft_abs(size->hmin);
	size->hmax = (size->hmax > size->hmin) ? size->hmax : size->hmin;
	while (y < size->size_c)
	{
		x = 0;
		while (x < size->size_l)
		{
			h = (map[y][x].heigth > 0) ? (double)map[y][x].heigth /
			(double)size->hmax : (double)-map[y][x].heigth / (double)size->hmax;
			map[y][x].color = ((int)(h * 200) * 65536) + 3604480 + 65280;
			tmp[y][x].color = map[y][x].color;
			x++;
		}
		y++;
	}
}

void	ft_change_blue(t_map **map, t_map **tmp, t_size *size)
{
	int		x;
	int		y;
	double	h;

	y = 0;
	size->hmin = ft_abs(size->hmin);
	size->hmax = (size->hmax > size->hmin) ? size->hmax : size->hmin;
	while (y < size->size_c)
	{
		x = 0;
		while (x < size->size_l)
		{
			h = (map[y][x].heigth > 0) ? (double)map[y][x].heigth /
			(double)size->hmax : (double)-map[y][x].heigth / (double)size->hmax;
			map[y][x].color = ((int)(h * 200) * 1) + 55 + 16711680;
			tmp[y][x].color = map[y][x].color;
			x++;
		}
		y++;
	}
}
