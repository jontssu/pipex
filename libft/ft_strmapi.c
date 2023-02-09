/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:35:28 by jole              #+#    #+#             */
/*   Updated: 2022/11/01 17:47:56 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (0);
	p = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s[i] != 0)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	p[i] = 0;
	return (p);
}
