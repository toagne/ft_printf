/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:12:23 by mpellegr          #+#    #+#             */
/*   Updated: 2024/05/20 14:16:53 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printint(int n);
int	ft_printuint(unsigned int n);
int	ft_printhexa(unsigned int ptr, char format);
int	ft_printptr(unsigned long ptr);
int	ft_printf(const char *str, ...);

#endif
