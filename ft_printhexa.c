/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:54:16 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/20 10:47:05 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hexa(int c, unsigned int ptr, char format)
{
	char	*str;
	int		mod;
	int		len;

	len = 0;
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (-1);
	str[c] = '\0';
	while (c != 0)
	{
		mod = ptr % 16;
		if (mod < 10)
			str[c - 1] = mod + '0';
		else if (mod >= 10 && format == 'x')
			str[c - 1] = (ptr % 16) - 10 + 'a';
		else if (mod >= 10 && format == 'X')
			str[c - 1] = (ptr % 16) - 10 + 'A';
		ptr /= 16;
		c--;
	}
	len += ft_printstr(str);
	free (str);
	return (len);
}

int	ft_printhexa(unsigned int ptr, char format)
{
	int				len;
	unsigned int	n;
	int				c;

	c = 0;
	n = ptr;
	len = 0;
	if (ptr == 0)
	{
		len += ft_printchar('0');
		return (len);
	}
	else
	{
		while (n > 0)
		{
			n /= 16;
			c++;
		}
		len += put_hexa(c, ptr, format);
		if (len == -1)
			return (-1);
	}
	return (len);
}
