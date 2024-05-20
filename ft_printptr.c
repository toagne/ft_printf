/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:13 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/20 16:05:53 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(int c, unsigned long ptr)
{
	char	*str;
	int		len;

	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (-1);
	str[c] = '\0';
	while (c != 0)
	{
		if (ptr % 16 < 10)
			str[c - 1] = (ptr % 16) + '0';
		else
			str[c - 1] = (ptr % 16) - 10 + 'a';
		ptr /= 16;
		c--;
	}
	len = ft_printstr(str);
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

int	count_len(unsigned long n)
{
	int	c;

	c = 0;
	while (n > 0)
	{
		n /= 16;
		c++;
	}
	return (c);
}

int	ft_printptr(unsigned long ptr)
{
	int				len;
	int				c;
	int				ptr_len;

	if ((write (1, "0x", 2)) == -1)
		return (-1);
	len = 2;
	if (ptr == 0)
	{
		len += ft_printchar('0');
		if (len == -1)
			return (-1);
	}
	else
	{
		c = count_len(ptr);
		ptr_len = put_ptr(c, ptr);
		if (ptr_len == -1)
			return (-1);
		len += ptr_len;
	}
	return (len);
}
