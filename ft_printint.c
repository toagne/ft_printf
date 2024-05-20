/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:56:13 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/20 14:40:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_printstr(num);
	free(num);
	return (len);
}
