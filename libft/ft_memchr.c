/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:40:40 by jole              #+#    #+#             */
/*   Updated: 2022/11/03 19:40:44 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n-- > 0)
	{
		if (*(unsigned char *)p == (unsigned char)c)
			return (p);
		p++;
	}
	return (0);
}
