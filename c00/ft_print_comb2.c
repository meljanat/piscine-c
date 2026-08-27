/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/08/27 02:36:59 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int a = 0;
	int b;
	int c;
	int d;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			c = a;
			d = b + 1;
			while (c <= 9)
			{
				while (d <= 9)
				{
					char ca = a + '0';
					char cb = b + '0';
					char cc = c + '0';
					char cd = d + '0';

					write(1, &ca, 1);
					write(1, &cb, 1);
					write(1, " ", 1);
					write(1, &cc, 1);
					write(1, &cd, 1);
					if (!(a == 9 && b == 8 && c == 9 && d == 9))
					{
						write(1, ",", 1);
						write(1, " ", 1);
					}
					d++;
				}
				c++;
				d = 0;
			}
			b++;
		}
		a++;
	}
}
