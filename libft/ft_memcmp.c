/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:49:42 by jole              #+#    #+#             */
/*   Updated: 2022/11/02 15:18:42 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p1;
	char	*p2;

	if (n == 0)
		return (0);
	p1 = (char *)s1;
	p2 = (char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *p1 == *p2)
	{
		n--;
		p1++;
		p2++;
	}
	return ((unsigned char)*p1 - (unsigned char)*p2);
}
