/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:23:26 by moguy             #+#    #+#             */
/*   Updated: 2019/01/28 04:20:23 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_is_hexa(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

void	check_color(char *line, int *i, int k)
{
	*i += 1;
	while (ft_is_white_space(line[*i]) == 0 && line[*i] != '\0')
	{
		if (line[*i] == '0' && (line[*i + 1] == 'x' || line[*i + 1] == 'X'))
			*i += 2;
		else
			ft_error();
		if (ft_is_hexa(line[*i]) == 1)
		{
			while (ft_is_hexa(line[*i]) == 1)
			{
				k++;
				*i += 1;
			}
			if (k > 6)
				ft_error();
		}
		else
			ft_error();
	}
}

void	hex_eption(t_size *size, char *line, int *i)
{
	size->color_switch = 1;
	check_color(line, i, 0);
}

int		check_line(char *line, t_size *size)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (line[i] != '\0')
	{
		while (ft_is_white_space(line[i]) == 1)
			i++;
		if (line[i] == '\0')
			return (k);
		if ((line[i] == '-' || line[i] == '+') && ft_isdigit(line[i + 1]) == 1)
			i++;
		while (line[i] != ',' && line[i] != ' ' && line[i] != '\0')
		{
			if (ft_isdigit(line[i]) == 0)
				ft_error();
			i++;
		}
		k++;
		if (line[i] == ',')
			hex_eption(size, line, &i);
	}
	return (k);
}

t_size	*ft_count_and_check(char *argv)
{
	int		fd;
	int		k;
	int		tmp;
	char	*line;
	t_size	*size;

	if (!(size = (t_size*)malloc(sizeof(t_size))))
		ft_error();
	size->color_switch = 0;
	size->size_c = 0;
	fd = open(argv, O_RDONLY);
	while ((k = get_next_line(fd, &line)) > 0)
	{
		size->size_l = check_line(line, size);
		if (size->size_c != 0)
			if (tmp != size->size_l)
				ft_error();
		tmp = size->size_l;
		size->size_c += 1;
		ft_strdel(&line);
	}
	if (k == -1 || (k == 0 && size->size_c == 0))
		ft_error();
	close(fd);
	return (size);
}
