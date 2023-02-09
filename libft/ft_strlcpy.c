/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:28:22 by jole              #+#    #+#             */
/*   Updated: 2022/11/02 15:20:05 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	slen;

	slen = ft_strlen(src);
	if (dstsize)
	{
		dstsize--;
		while (dstsize && *src != 0)
		{
			dstsize--;
			*dst++ = *src++;
		}
		*dst = '\0';
	}
	return (slen);
}
