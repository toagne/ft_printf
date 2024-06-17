/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:17 by mpellegr          #+#    #+#             */
/*   Updated: 2024/06/17 16:10:04 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(va_list *args, const char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len = ft_printchar(va_arg(*args, int));
	else if (format == 's')
		len = ft_printstr(va_arg(*args, char *));
	else if (format == 'p')
		len = ft_printptr(va_arg(*args, unsigned long));
	else if (format == 'd' || format == 'i')
		len = ft_printint(va_arg(*args, int));
	else if (format == 'u')
		len = ft_printuint(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_printhexa(va_arg(*args, unsigned long), format);
	else if (format == '%')
		len = ft_printchar('%');
	return (len);
}

int	real_printf(va_list *args, const char *str)
{
	int	printf_len;
	int	tot_len;

	tot_len = 0;
	while (*str != 0)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			printf_len = find_format(args, *str);
			if (printf_len == -1)
				return (-1);
			tot_len = tot_len + printf_len;
		}
		else
		{
			if ((ft_printchar(*str)) == -1)
				return (-1);
			tot_len++;
		}
		str++;
	}
	return (tot_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printf_len;
	int		n;

	n = 0;
	va_start(args, str);
	while (str[n] != '\0')
	{
		if (str[n] == '%' && str[n + 1] == '\0' && str[n - 1] != '%')
		{
			if ((write(1, str, (ft_strlen(str) - 1))) == -1)
				return (-1);
			return (ft_strlen(str) - 1);
		}
		n++;
	}
	printf_len = real_printf(&args, str);
	if (printf_len == -1)
		return (-1);
	va_end(args);
	return (printf_len);
}
