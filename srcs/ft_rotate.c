/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 03:03:10 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:04:32 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_scale(t_map *map, t_mlx *mlx)
{
	double	x;
	double	y;
	double	z;

	x = round((double)(map->x * mlx->scale));
	y = round((double)(map->y * mlx->scale));
	z = round((double)(map->heigth * mlx->scale));
	map->x = x;
	map->y = y;
	map->heigth = z;
}

void	ft_rotate(t_map *map, t_size *size, int axe)
{
	int		v[3];

	if (axe == 1)
	{
		v[0] = map->x;
		v[1] = round(map->y * cos(SX) - (map->heigth * sin(SX)));
		v[2] = round(map->y * sin(SX) + (map->heigth * cos(SX)));
	}
	if (axe == 2)
	{
		v[0] = round(map->x * cos(SY) + (map->heigth * sin(SY)));
		v[1] = map->y;
		v[2] = round(-(map->x * sin(SY)) + (map->heigth * cos(SY)));
	}
	if (axe == 3)
	{
		v[0] = round(map->x * cos(SZ) - (map->y * sin(SZ)));
		v[1] = round(map->x * sin(SZ) + (map->y * cos(SZ)));
		v[2] = map->heigth;
	}
	map->x = v[0];
	map->y = v[1];
	map->heigth = v[2];
}

void	ft_finaltouch(t_pack *pack)
{
	int		x;
	int		y;
	int		xp;
	int		yp;

	xp = 1 * (int)(PS->px - PM[PS->size_c / 2][PS->size_l / 2].x);
	yp = 1 * (int)(PS->py - PM[PS->size_c / 2][PS->size_l / 2].y);
	y = 0;
	while (y < PS->size_c)
	{
		x = 0;
		while (x < PS->size_l)
		{
			PM[y][x].x += xp;
			PM[y][x].y += yp;
			x++;
		}
		y++;
	}
}

void	ft_change(t_pack *pack)
{
	int		x;
	int		y;

	PS->px = (WIDTH / 2) + PS->decal_x;
	PS->py = (HEIGTH / 2) + PS->decal_y;
	y = 0;
	while (y < PS->size_c)
	{
		x = 0;
		while (x < PS->size_l)
		{
			apply_scale(&PM[y][x], PX);
			ft_rotate(&PM[y][x], PS, 1);
			ft_rotate(&PM[y][x], PS, 2);
			ft_rotate(&PM[y][x], PS, 3);
			if (PM[y][x].heigth < PS->hrmin)
				PS->hrmin = PM[y][x].heigth;
			if (PM[y][x].heigth > PS->hrmax)
				PS->hrmax = PM[y][x].heigth;
			x++;
		}
		y++;
	}
	ft_finaltouch(pack);
}
