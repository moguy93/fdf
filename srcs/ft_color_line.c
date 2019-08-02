/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:43:06 by moguy             #+#    #+#             */
/*   Updated: 2019/02/17 20:38:08 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_color_plus(t_coord *coord1, int tmp)
{
	if (coord1->db != 0)
	{
		tmp = (int)coord1->ddb;
		if (tmp != 0)
			coord1->color = coord1->color + (tmp * 65536);
		coord1->ddb = ((double)coord1->db / (double)coord1->dc) +
													coord1->ddb - (double)tmp;
	}
	if (coord1->dv != 0)
	{
		tmp = (int)coord1->ddv;
		if (tmp != 0)
			coord1->color = coord1->color + (tmp * 256);
		coord1->ddv = ((double)coord1->dv / (double)coord1->dc) +
													coord1->ddv - (double)tmp;
	}
	if (coord1->dr != 0)
	{
		tmp = (int)coord1->ddr;
		if (tmp != 0)
			coord1->color = coord1->color + tmp;
		coord1->ddr = ((double)coord1->dr / (double)coord1->dc) +
													coord1->ddr - (double)tmp;
	}
}

void		ft_color_line(t_coord *coord1, t_coord *coord2, int i)
{
	int		tmp;

	tmp = 0;
	if (i == 0)
	{
		coord1->db = (coord2->color / 65536) - (coord1->color / 65536);
		coord1->dc = (coord1->dx > coord1->dy) ? coord1->dx : coord1->dy;
		coord1->ddb = (double)coord1->db / (double)coord1->dc;
		coord1->coltmp = coord1->color % 65536;
		coord2->coltmp = coord2->color % 65536;
		if (coord1->coltmp != 0 && coord2->coltmp != 0)
		{
			coord1->dv = (coord2->coltmp / 256) - (coord1->coltmp / 256);
			coord1->dr = (coord2->coltmp % 256) - (coord1->coltmp % 256);
			coord1->ddv = (double)coord1->dv / (double)coord1->dc;
			coord1->ddr = (double)coord1->dr / (double)coord1->dc;
		}
		else
		{
			coord1->dv = 0;
			coord1->dr = 0;
		}
	}
	ft_color_plus(coord1, tmp);
}
