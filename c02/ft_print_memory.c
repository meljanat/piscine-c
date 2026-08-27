/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 02:00:00 by mel-jana          #+#    #+#             */
/*   Updated: 2026/08/27 02:34:57 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(unsigned long addr)
{
	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, buffer, 16);
	write(1, ": ", 2);
}

void	print_hex_content(unsigned char *ptr, unsigned int chunk)
{
	char			*hex;
	unsigned char	c;

	hex = "0123456789abcdef";
	for (unsigned int i = 0; i < 16; i++)
	{
		if (i < chunk)
		{
			c = ptr[i];
			write(1, &hex[c / 16], 1);
			write(1, &hex[c % 16], 1);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i % 2 == 1)
			write(1, " ", 1);
	}
}

void	print_printable_content(unsigned char *ptr, unsigned int chunk)
{
	for (unsigned int i = 0; i < chunk; i++)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 0)
		return (addr);

	unsigned char *ptr = (unsigned char *)addr;
	unsigned int offset = 0;

	while (offset < size)
	{
		unsigned int chunk = (size - offset >= 16) ? 16 : (size - offset);

		print_address((unsigned long)(ptr + offset));

		print_hex_content(ptr + offset, chunk);

		print_printable_content(ptr + offset, chunk);

		write(1, "\n", 1);
		offset += 16;
	}

	return (addr);
}
