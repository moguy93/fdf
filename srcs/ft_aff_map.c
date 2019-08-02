/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:41:34 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:08:49 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	choice2(void *pack, int x, int y)
{
	PC->color = PM[y][x].color;
	PC->h = PM[y][x].heigth;
	PC->x = PM[y][x].x;
	PC->y = PM[y][x].y;
	fill_pixel(PX->data, PC, PX, PC->color);
	if (x < (PS->size_l - 1) && PX->scale > 1)
	{
		PC1->color = PM[y][x + 1].color;
		PC1->h = PM[y][x + 1].heigth;
		PC1->x = PM[y][x + 1].x;
		PC1->y = PM[y][x + 1].y;
		draw_line(PX, PC1, PC);
	}
	if (y < (PS->size_c - 1) && PX->scale > 1)
	{
		PC2->color = PM[y + 1][x].color;
		PC2->h = PM[y + 1][x].heigth;
		PC2->x = PM[y + 1][x].x;
		PC2->y = PM[y + 1][x].y;
		draw_line(PX, PC, PC2);
	}
}

void	choice1(void *pack, int x, int y)
{
	PC->color = PM[y][x].color;
	PC->h = PM[y][x].heigth * PX->scale;
	PC->x = x * PX->scale + PS->px;
	PC->y = y * PX->scale + PS->py;
	fill_pixel(PX->data, PC, PX, PC->color);
	if (x < (PS->size_l - 1) && PX->scale > 1)
	{
		PC1->color = PM[y][x + 1].color;
		PC1->h = PM[y][x + 1].heigth;
		PC1->x = (x + 1) * PX->scale + PS->px;
		PC1->y = y * PX->scale + PS->py;
		draw_line(PX, PC1, PC);
	}
	if (y < (PS->size_c - 1) && PX->scale > 1)
	{
		PC2->color = PM[y + 1][x].color;
		PC2->h = PM[y + 1][x].heigth;
		PC2->x = x * PX->scale + PS->px;
		PC2->y = (y + 1) * PX->scale + PS->py;
		draw_line(PX, PC, PC2);
	}
	PM[y][x].x = x;
	PM[y][x].y = y;
}

void	aff_map_plus(void *pack, int mode)
{
	int		x;
	int		y;

	y = 0;
	while (y < PS->size_c)
	{
		x = 0;
		while (x < PS->size_l)
		{
			if (mode == 1)
				choice1((t_pack*)pack, x, y);
			else
				choice2((t_pack*)pack, x, y);
			x++;
		}
		y++;
	}
}

void	ft_reaff_map(t_map **map, t_mlx *mlx, t_size *size)
{
	t_pack	pack;

	if (!(pack.coord = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	if (!(pack.coord1 = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	if (!(pack.coord2 = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	pack.size = size;
	pack.map = map;
	pack.mlx = mlx;
	aff_map_plus(&pack, 2);
	ft_free_coord(pack.coord);
	ft_free_coord(pack.coord1);
	ft_free_coord(pack.coord2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	ft_text(mlx, size);
}

void	ft_aff_map(t_map **map, t_mlx *mlx, t_size *size)
{
	t_pack	pack;

	if (!(pack.coord = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	if (!(pack.coord1 = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	if (!(pack.coord2 = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	size->px = (WIDTH / 2) - (((size->size_l - 1) * mlx->scale) / 2);
	size->py = (HEIGTH / 2) - (((size->size_c - 1) * mlx->scale) / 2);
	pack.size = size;
	pack.map = map;
	pack.mlx = mlx;
	aff_map_plus(&pack, 1);
	ft_free_coord(pack.coord);
	ft_free_coord(pack.coord1);
	ft_free_coord(pack.coord2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	ft_text(mlx, size);
}
