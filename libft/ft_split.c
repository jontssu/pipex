/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:10:52 by jole              #+#    #+#             */
/*   Updated: 2022/11/03 21:27:34 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c);
static void	ft_make_array(char **array, char const *s, char c);
static void	ft_fill_array(char **array, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		wcount;
	char	**array;
	int		i;

	if (!s)
		return (0);
	i = 0;
	wcount = ft_wordcount(s, c);
	array = malloc((wcount + 1) * sizeof(char *));
	if (!array)
		return (0);
	ft_make_array(array, s, c);
	ft_fill_array(array, s, c);
	return (array);
}

static	int	ft_wordcount(char const *s, char c)
{
	int	wcount;
	int	i;

	wcount = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			i++;
			if (s[i] == c || s[i] == 0)
				wcount++;
		}
	}
	return (wcount);
}

static	void	ft_make_array(char **array, char const *s, char c)
{
	int	wsize;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		wsize = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			wsize++;
			i++;
		}
		if (wsize > 0)
		{
			array[j] = malloc((wsize + 1) * sizeof(char));
			if (!array[j])
				return ;
			j++;
		}
	}
}

static	void	ft_fill_array(char **array, char const *s, char c)
{
	int	g;
	int	i;
	int	j;

	j = 0;
	g = 0;
	while (s[g] != 0)
	{
		i = 0;
		while (s[g] == c)
			g++;
		while (s[g] != c && s[g] != 0)
		{
			array[j][i] = s[g];
			g++;
			i++;
			if (s[g] == c || s[g] == 0)
			{
				array[j][i] = '\0';
				j++;
			}
		}
	}
	array[j] = 0;
}
