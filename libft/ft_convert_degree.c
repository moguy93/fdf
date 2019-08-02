/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_degree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 03:30:17 by moguy             #+#    #+#             */
/*   Updated: 2019/01/30 05:24:50 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_to_degree(double radians)
{
	return (radians * (180.0 / M_PI));
}

double		ft_to_radians(double degree)
{
	return (degree / (180.0 / M_PI));
}
