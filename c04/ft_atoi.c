/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jana <mel-jana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:55:59 by mouad             #+#    #+#             */
/*   Updated: 2026/08/17 19:03:25 by mel-jana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *escape_space_mp(char *str)
{
    int foundmp;
    int foundchar;
    char *s;
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        if ((str[i] == ' ' || str[i] == '\t') && !foundchar)
        {
            i++;
            continue;
        }
        else if ()
    }
}

int ft_atoi(char *str)
{
    char *s;
    int result;
    int i;
    int neg;

    s = escape_space_mp(str);
    i = 0;
    neg = 0;
    result = 0;
    while (s[i])
    {
        if (s[i] == '-')
            neg = 1;
        else if (s[i] >= '0' && s[i] <= '9')
            result = result * 10 + (s[i] - '0');
        else
            return result;
        i++;
    }
    if (neg)
    result *= -1;
    return result;
}