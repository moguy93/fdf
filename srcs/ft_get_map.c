/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:09:05 by moguy             #+#    #+#             */
/*   Updated: 2019/06/19 06:09:51 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_color(char *line, int *i, t_map *map)
{
	char	*hexa;
	int		j;

	j = 0;
	*i += 1;
	hexa = ft_strnew(7);
	hexa[6] = '\0';
	while (ft_is_white_space(line[*i]) == 0 && line[*i] != '\0')
	{
		if ((line[*i] == '0' && (line[*i + 1] == 'x' || line[*i + 1] == 'X')))
			*i += 2;
		while (ft_is_hexa(line[*i]) == 1)
		{
			hexa[j++] = line[*i];
			*i += 1;
		}
	}
	map->color = ft_convert_color(hexa);
}

void	fill_plus(t_map *map, char *line, t_size *size, int *i)
{
	if (map->heigth < size->hmin)
		size->hmin = map->heigth;
	if (map->heigth > size->hmax)
		size->hmax = map->heigth;
	if (line[*i] == ',')
		fill_color(line, i, map);
	else
		map->color = 16777215;
}

void	fill_map(char *line, t_map *map, t_size *size, int k)
{
	int		nb;
	int		neg;
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		nb = 0;
		neg = 1;
		while (ft_is_white_space(line[i]) == 1)
			i++;
		if (line[i] == '-' || line[i] == '+')
			neg = (line[i++] == '-') ? -1 : 1;
		while (line[i + j] != ',' && line[i + j] != ' ' && line[i + j] != '\0')
		{
			nb = (line[i + j] - '0') + nb * ft_power(10, j);
			j++;
		}
		i = i + j;
		map[k].heigth = nb * neg;
		fill_plus(&map[k], line, size, &i);
		k++;
	}
}

t_map	**ft_get_map(char *argv, t_size *size)
{
	t_map	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	size->hmax = 0;
	fd = open(argv, O_RDONLY);
	if (!(map = (t_map**)malloc(sizeof(t_map*) * size->size_c)))
		ft_error();
	while (get_next_line(fd, &line) > 0)
	{
		if (!(map[i] = (t_map*)malloc(sizeof(t_map) * size->size_l)))
			ft_error();
		fill_map(line, map[i], size, 0);
		i++;
		ft_strdel(&line);
	}
	close(fd);
	return (map);
}
