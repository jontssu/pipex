/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:07:21 by jole              #+#    #+#             */
/*   Updated: 2022/11/02 15:21:08 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*p;
	char	*save;

	if (!s1)
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && i < len)
		i++;
	while (ft_strchr(set, s1[len - 1]) && i < len)
		len--;
	p = malloc(len - i + 1);
	if (!p)
		return (0);
	save = p;
	while (len - i)
	{
		*p = s1[i];
		i++;
		p++;
	}
	*p = 0;
	return (save);
}
