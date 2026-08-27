/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/08/27 02:00:00 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		check_base(char *base);
int		ft_atoi_base(char *str, char *base);

void	ft_putnbr_base_len(long nbr, char *base, int *len)
{
	long	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		*len += 1;
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base_len(nbr / base_len, base, len);
	*len += 1;
}

void	ft_putnbr_base(long nbr, char *base, char *res, int *i)
{
	long	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		res[*i] = '-';
		*i += 1;
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base, res, i);
	res[*i] = base[nbr % base_len];
	*i += 1;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	n;
	int		len;
	char	*res;
	int		i;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	len = 0;
	ft_putnbr_base_len(n, base_to, &len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	ft_putnbr_base(n, base_to, res, &i);
	res[i] = '\0';
	return (res);
}
