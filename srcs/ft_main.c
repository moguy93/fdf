/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:10:48 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:11:10 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	**ft_map_copy(t_map **map, t_size *size)
{
	int		x;
	int		y;
	t_map	**copy;

	y = 0;
	if (!(copy = (t_map**)malloc(sizeof(t_map*) * size->size_c)))
		ft_error();
	while (y < size->size_c)
	{
		x = 0;
		if (!(copy[y] = (t_map*)malloc(sizeof(t_map) * size->size_l)))
			ft_error();
		while (x < size->size_l)
		{
			copy[y][x].heigth = map[y][x].heigth;
			copy[y][x].color = map[y][x].color;
			copy[y][x].x = map[y][x].x;
			copy[y][x].y = map[y][x].y;
			x++;
		}
		y++;
	}
	return (copy);
}

void	init_size(t_size *size, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < (WIDTH * HEIGTH))
	{
		mlx->depth[i] = 0;
		i++;
	}
	size->decal_x = 0;
	size->decal_y = 0;
	size->speed_x = 0;
	size->speed_y = 0;
	size->speed_z = 0;
	size->hmin = 0;
	size->hmax = 0;
	size->hrmin = 0;
	size->hrmax = 0;
	mlx->scale = fmin(WIDTH / 2 / size->size_c, HEIGTH / 2 / size->size_l);
	mlx->scale = fmax(mlx->scale, 1);
}

void	init_pack(t_pack *pack, t_size *size, t_mlx *mlx, t_map **map)
{
	pack->tmp = ft_map_copy(map, size);
	pack->tmp2 = ft_map_copy(map, size);
	pack->map = map;
	pack->mlx = mlx;
	pack->size = size;
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;
	t_size		*size;
	t_map		**map;
	t_pack		pack;

	if (argc != 2)
		ft_usage();
	if (!(mlx.mlx_ptr = mlx_init()))
		ft_error();
	if (!(mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGTH, "mlx_test")))
		ft_error();
	mlx.img = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGTH);
	mlx.data = mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.siz), &(mlx.end));
	if (!(mlx.depth = (int*)malloc(sizeof(int) * (WIDTH * HEIGTH))))
		ft_error();
	size = ft_count_and_check(argv[1]);
	init_size(size, &mlx);
	map = ft_get_map(argv[1], size);
	ft_aff_map(map, &mlx, size);
	init_pack(&pack, size, &mlx, map);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, deal_key, &pack);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
