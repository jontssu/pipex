/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:07:45 by jole              #+#    #+#             */
/*   Updated: 2022/11/07 22:55:43 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		sub_s = malloc(1);
		if (!sub_s)
			return (0);
		*sub_s = 0;
		return (sub_s);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start + 1;
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (0);
	if (start <= ft_strlen(s))
		ft_strlcpy(sub_s, (s + start), len + 1);
	sub_s[len] = '\0';
	return (sub_s);
}
