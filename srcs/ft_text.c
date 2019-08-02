/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 06:12:45 by moguy             #+#    #+#             */
/*   Updated: 2019/01/29 01:08:01 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_text_suite(t_mlx *mlx, t_size *size, char *str)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 100, 0x00ffffff,
			"\nRotation sur l'axe z (touches / et *) : ");
	if (!(str = ft_itoa((int)ft_to_degree(SZ) % 360)))
		ft_error();
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 450, 100, 0x00bf00ff, str);
	ft_strdel(&str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 125, 0x00ffffff,
			"\nEchelle (touches - et +) : ");
	if (!(str = ft_itoa((int)mlx->scale)))
		ft_error();
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 325, 125, 0x00ffcc00, str);
	ft_strdel(&str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 150, 0x00ffffff,
			"\nReset : ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 130, 150, 0x00ffcc00,
			"tab");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 175, 0x00ffffff,
			"\nSet de couleur : ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 220, 175, 0x00e60000, "R ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 240, 175, 0x00ffffff, "or ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 270, 175, 0x0033cc33, "V ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 290, 175, 0x00ffffff, "or ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 320, 175, 0x000099ff, "B");
}

void	ft_text(t_mlx *mlx, t_size *size)
{
	char	*str;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0x00ffffff,
			"Rotation sur l'axe x (touches 8 et 2) : ");
	if (!(str = ft_itoa((int)ft_to_degree(SX) % 360)))
		ft_error();
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 450, 50, 0x00bf00ff, str);
	ft_strdel(&str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 75, 0x00ffffff,
			"\nRotation sur l'axe y (touches 4 et 6) : ");
	if (!(str = ft_itoa((int)ft_to_degree(SY) % 360)))
		ft_error();
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 450, 75, 0x00bf00ff, str);
	ft_strdel(&str);
	ft_text_suite(mlx, size, str);
}
