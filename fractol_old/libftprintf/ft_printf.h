/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:44:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/03/04 21:14:46 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(unsigned long num, int base, int isUpperCase);
int	print_signed_digit(long num, int base);
int	print_ptr(void *ptr);
int	print_format(char specifier, va_list *ap);
int	ft_printf(const char *format, ...);

#endif
