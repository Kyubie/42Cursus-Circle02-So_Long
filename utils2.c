/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:40:26 by grannou           #+#    #+#             */
/*   Updated: 2022/01/14 12:40:35 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_digit(int n)
{
	int		count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0 && ++count)
		n = n / 10;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_count;
	long	nbr;
	int		i;

	nbr = n;
	digit_count = count_digit(nbr);
	str = (char *)malloc(sizeof(char) * (digit_count + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
		i++;
	}
	str[digit_count] = '\0';
	while (digit_count > i)
	{
		str[--digit_count] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
