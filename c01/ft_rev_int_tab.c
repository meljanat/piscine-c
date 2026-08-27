/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/08/27 02:36:08 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int start = 0;
	while (start < size / 2)
	{
		int temp = tab[start];
		tab[start] = tab[size - start - 1];
		tab[size - start - 1] = temp;
		start++;
	}
}
