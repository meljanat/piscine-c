/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/09/01 15:17:48 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int count_words(char *str, char *charset)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 0 && is_sep(str[i + 1], charset) == 1)
			words++;
		i++;
	}
	return (words);
}

char *ft_strndup(char *src, int n)
{
	char *dest;
	int i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **ft_split(char *str, char *charset)
{
	char **res;
	int i;
	int j;
	int len;

	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			len = 0;
			while (is_sep(str[i + len], charset) == 0)
				len++;
			res[j] = ft_strndup(str + i, len);
			j++;
			i += len;
		}
	}
	res[j] = NULL;
	return (res);
}
