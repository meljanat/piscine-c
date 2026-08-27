/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/08/27 02:00:00 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

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

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

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

void	write_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (is_sep(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_alloc_word(char *str, char *charset)
{
	int		len;
	char	*word;

	len = 0;
	while (is_sep(str[len], charset) == 0)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	write_word(word, str, charset);
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

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
			res[j] = ft_alloc_word(str + i, charset);
			j++;
			while (str[i] && is_sep(str[i], charset) == 0)
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}
