/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:00:53 by jole              #+#    #+#             */
/*   Updated: 2022/10/31 16:10:15 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = dst;
	src2 = (char *)src;
	while (n)
	{
		n--;
		*dst2++ = *src2++;
	}
	return (dst);
}
