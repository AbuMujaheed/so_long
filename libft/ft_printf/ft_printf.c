/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:08:40 by sojetimi          #+#    #+#             */
/*   Updated: 2025/02/03 18:34:11 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_format(char c, va_list args, int *count)
{
	if (c == 's')
		(*count) += ft_print_string(va_arg(args, char *));
	else if (c == 'c')
		(*count) += ft_print_char((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		(*count) += ft_print_number(va_arg(args, int), 10, DEC);
	else if (c == 'u')
		(*count) += ft_print_number(
				(unsigned long)va_arg(args, unsigned int), 10, DEC);
	else if (c == 'x')
		(*count) += ft_print_number(
				va_arg(args, unsigned int), 16, HEX);
	else if (c == 'X')
		(*count) += ft_print_number(
				va_arg(args, unsigned int), 16, UP_HEX);
	else if (c == 'p')
		(*count) += ft_print_pointer(
				(unsigned long long)va_arg(args, void *), 16, HEX);
	else
		(*count) += write(1, &c, 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i])
				ft_handle_format(str[i], args, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
