/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:01:14 by moguy             #+#    #+#             */
/*   Updated: 2019/01/29 01:28:34 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_usage(void)
{
	ft_putstr("usage: ./fdf [file_name]\n");
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_SUCCESS);
}
