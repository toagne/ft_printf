/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:55:04 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/20 15:21:30 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	put_uint(int c, unsigned int n)
{
	char	*num;
	int		len;

	num = (char *)malloc(sizeof(char) * (c + 1));
	if (!num)
		return (-1);
	num[c] = '\0';
	while (c != 0)
	{
		num[c - 1] = (n % 10) + '0';
		n /= 10;
		c--;
	}
	len = ft_printstr(num);
	free (num);
	return (len);
}

int	ft_printuint(unsigned int n)
{
	int				len;
	unsigned int	n1;
	int				c;

	n1 = n;
	len = 0;
	if (n == 0)
	{
		len += ft_printchar('0');
		if (len == -1)
			return (-1);
	}
	else
	{
		c = 0;
		while (n1 != 0)
		{
			n1 = n1 / 10;
			c++;
		}
		len += put_uint(c, n);
		if (len == -1)
			return (-1);
	}
	return (len);
}
