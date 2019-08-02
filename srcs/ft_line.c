/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:17:33 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:10:20 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_pixel(char *data, t_coord *coord, t_mlx *mlx, int color)
{
	int		pos;

	if (coord->x >= WIDTH || coord->y >= HEIGTH || coord->x < 0 || coord->y < 0)
		return ;
	pos = ((coord->y * WIDTH) + coord->x) * 4;
	if (mlx->depth[(coord->y * WIDTH) + coord->x] <= coord->h ||
			(data[pos] == 0 && data[pos + 1] == 0 && data[pos + 2] == 0))
		mlx->depth[(coord->y * WIDTH) + coord->x] = coord->h;
	else
		return ;
	data[pos] = color >> 16 & 255;
	data[pos + 1] = color >> 8 & 255;
	data[pos + 2] = color & 255;
}

int		road1(int cumul, t_mlx *mlx, t_coord *coord1, t_coord *coord2)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	cumul = coord1->dx / 2;
	while (i <= coord1->dx)
	{
		coord1->x += coord1->xinc;
		cumul += coord1->dy;
		if (cumul >= coord1->dx)
		{
			cumul -= coord1->dx;
			coord1->y += coord1->yinc;
		}
		if (coord1->color != coord2->color)
		{
			ft_color_line(coord1, coord2, j);
			j++;
		}
		fill_pixel(mlx->data, coord1, mlx, coord1->color);
		i++;
	}
	return (0);
}

int		road2(int cumul, t_mlx *mlx, t_coord *coord1, t_coord *coord2)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	cumul = coord1->dy / 2;
	while (i <= coord1->dy)
	{
		coord1->y += coord1->yinc;
		cumul += coord1->dx;
		if (cumul >= coord1->dy)
		{
			cumul -= coord1->dy;
			coord1->x += coord1->xinc;
		}
		if (coord1->color != coord2->color)
		{
			ft_color_line(coord1, coord2, j);
			j++;
		}
		fill_pixel(mlx->data, coord1, mlx, coord1->color);
		i++;
	}
	return (0);
}

int		draw_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2)
{
	int		cumul;

	cumul = 0;
	coord1->ddb = 0;
	coord1->ddv = 0;
	coord1->ddr = 0;
	coord1->dx = coord2->x - coord1->x;
	coord1->dy = coord2->y - coord1->y;
	coord1->xinc = (coord1->dx > 0) ? 1 : -1;
	coord1->yinc = (coord1->dy > 0) ? 1 : -1;
	coord1->dx = ft_abs(coord1->dx);
	coord1->dy = ft_abs(coord1->dy);
	if (coord1->dx > coord1->dy)
		road1(cumul, mlx, coord1, coord2);
	else
		road2(cumul, mlx, coord1, coord2);
	if (coord1->y < coord2->y)
		fill_pixel(mlx->data, coord2, mlx, coord2->color);
	else
		fill_pixel(mlx->data, coord1, mlx, coord1->color);
	return (0);
}
