/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:48:35 by jole              #+#    #+#             */
/*   Updated: 2023/02/13 15:23:57 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*strlen_delim(char *str, int *full_len, int delim)
{
	while (*str != delim && *str)
	{
		str++;
		(*full_len)++;
	}
	return (str);
}

int	calc_words(char *str, int *full_len, int delim)
{
	int		words;
	int		quote;

	*full_len = 0;
	words = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str)
			words++;
		if (*str == '\"' || *str == '\'')
		{
			quote = *str;
			str++;
			str = strlen_delim(str, full_len, quote);
		}
		else
			str = strlen_delim(str, full_len, delim);
	}
	return (words);
}

char	*copy_to_split2(char *str, int *strlen)
{
	int	quote;

	quote = *str;
	str++;
	strlen_delim(str, strlen, quote);
	return (str);
}

void	copy_to_split(char *str, char **split, int delim, int words)
{
	int		i;
	char	*tmp;
	int		strlen;

	i = 0;
	tmp = (char *)(split + words);
	while (words-- > 1)
	{
		split[i] = tmp;
		strlen = 0;	
		while (*str == delim)
			str++;
		if (*str == '\"' || *str == '\'')
			str = copy_to_split2(str, &strlen);
		else
			strlen_delim(str, &strlen, delim);
		ft_strlcpy(split[i++], str, strlen + 1);
		if (*str == '\"' || *str == '\'')
			str++;
		str += strlen + 1;
		tmp += strlen + 1;
	}
	split[i] = NULL;
}

char	**split_quote(char *str, int delim)
{
	char	**split;
	int		len;
	int		words;

	words = calc_words(str, &len, delim) + 1;	
	split = ft_calloc(words * sizeof(char *) + \
			((words - 1) + len) * sizeof(char), 1);
	if (!split)
	{
		perror("Error in single_mlc_split_quotes");
		return (NULL);
	}
	copy_to_split(str, split, delim, words);
	return (split);
}
