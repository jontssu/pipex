/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:28:44 by jole              #+#    #+#             */
/*   Updated: 2022/11/02 17:05:24 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calculate_digits(int n);
static char		*allocate_nb_to_str(char *p, long n, int is_negative);
static char		*strrev(char *p);

char	*ft_itoa(int n)
{
	char	*p;
	int		digits;
	int		is_negative;

	is_negative = 0;
	digits = calculate_digits(n);
	if (n < 0)
		is_negative = 1;
	p = malloc((digits + is_negative + 1) * sizeof(char));
	if (!p)
		return (0);
	p = allocate_nb_to_str(p, n, is_negative);
	return (strrev(p));
}

static int	calculate_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (digits + 1);
	if (n < 0)
	{
		digits++;
		n = n / -10;
	}
	while (n > 0)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static char	*allocate_nb_to_str(char *p, long n, int is_negative)
{
	int	i;

	i = 0;
	if (is_negative)
		n = n * -1;
	if (n == 0)
		p[i++] = '0';
	while (n > 0)
	{
		p[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_negative)
		p[i++] = '-';
	p[i] = '\0';
	return (p);
}

static char	*strrev(char *p)
{
	int		i;
	int		k;
	char	tmp;

	i = 0;
	k = ft_strlen(p) - 1;
	while (i < k)
	{
		tmp = p[i];
		p[i++] = p[k];
		p[k--] = tmp;
	}
	return (p);
}
