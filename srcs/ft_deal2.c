/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 04:20:52 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:09:23 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_coord(t_coord *coord)
{
	free(coord);
	coord = NULL;
}

void	ft_free_map(t_map **map, t_size *size)
{
	int x;

	x = -1;
	while (++x < size->size_c)
		free(map[x]);
	free(map);
	map = NULL;
}

void	deal_decal(int key, void *pack)
{
	if (key == 69)
		PX->scale *= 1.1;
	if (key == 78)
		PX->scale *= 0.9;
	if (key == 123)
		PS->decal_x -= 20;
	if (key == 124)
		PS->decal_x += 20;
	if (key == 125)
		PS->decal_y += 20;
	if (key == 126)
		PS->decal_y -= 20;
}

void	deal_rotate(int key, void *pack)
{
	if (key == 91)
		PS->speed_x += ft_to_radians(3);
	if (key == 84)
		PS->speed_x -= ft_to_radians(3);
	if (key == 88)
		PS->speed_y += ft_to_radians(3);
	if (key == 86)
		PS->speed_y -= ft_to_radians(3);
	if (key == 67)
		PS->speed_z += ft_to_radians(3);
	if (key == 75)
		PS->speed_z -= ft_to_radians(3);
}
