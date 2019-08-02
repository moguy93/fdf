/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:22:55 by moguy             #+#    #+#             */
/*   Updated: 2018/11/24 15:15:34 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cp;
	int		i;

	cp = (char*)s;
	i = 0;
	if (cp[i] == c)
		return (&cp[i]);
	while (cp[i] != c && cp[i])
	{
		if (cp[i] == c)
			return (&cp[i]);
		i++;
	}
	if (c == cp[i])
		return (&cp[i]);
	return (NULL);
}
