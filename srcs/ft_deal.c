/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:27:07 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:09:08 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	deal_exit(void *pack)
{
	mlx_destroy_image(PX->mlx_ptr, PX->img);
	mlx_destroy_window(PX->mlx_ptr, PX->win_ptr);
	ft_free_map(PM, PS);
	ft_free_map(PT, PS);
	free(PS);
	PS = NULL;
	exit(EXIT_SUCCESS);
}

void	deal_reset(void *pack)
{
	if (PS->color_switch == 0)
		ft_change_white(PM, PT, PS);
	else
	{
		ft_free_map(PM, PS);
		PM = ft_map_copy(PT2, PS);
		ft_free_map(PT, PS);
		PT = ft_map_copy(PT2, PS);
	}
	PS->decal_x = 0;
	PS->decal_y = 0;
	PS->speed_x = 0;
	PS->speed_y = 0;
	PS->speed_z = 0;
	PX->scale = fmin(WIDTH / 2 / PS->size_c, HEIGTH / 2 / PS->size_l);
	PX->scale = fmax(PX->scale, 1);
}

void	deal_color(int key, void *pack)
{
	if (key == 11)
		ft_change_blue(PM, PT, PS);
	if (key == 9)
		ft_change_green(PM, PT, PS);
	if (key == 15)
		ft_change_red(PM, PT, PS);
}

int		deal_key(int key, void *pack)
{
	ft_free_map(PM, PS);
	PM = ft_map_copy(PT, PS);
	if (key == 11 || key == 9 || key == 15)
		deal_color(key, pack);
	if (key == 67 || key == 75 || key == 84 || key == 86 || key == 88 ||
			key == 91)
		deal_rotate(key, pack);
	if (key == 69 || key == 78 || (key >= 123 && key <= 126))
		deal_decal(key, pack);
	if (key == 48)
		deal_reset(pack);
	if (key == 53)
		deal_exit(pack);
	if (key == 34)
	{
		deal_reset(pack);
		PS->speed_x = ft_to_radians(30);
		PS->speed_z = ft_to_radians(45);
	}
	ft_change(pack);
	ft_bzero(PX->data, (HEIGTH * WIDTH * 4));
	mlx_put_image_to_window(PX->mlx_ptr, PX->win_ptr, PX->img, 0, 0);
	ft_reaff_map(PM, PX, PS);
	return (0);
}
