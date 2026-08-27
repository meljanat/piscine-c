/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/08/27 02:00:00 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += (size - 1) * ft_strlen(sep);
	return (total_len);
}

void	ft_concat_strs(char *ptr, int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
		i++;
	}
	*ptr = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;

	if (size == 0)
	{
		res = (char *)malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (!res)
		return (NULL);
	ft_concat_strs(res, size, strs, sep);
	return (res);
}
