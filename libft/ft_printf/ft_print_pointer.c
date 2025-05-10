/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:09:06 by sojetimi          #+#    #+#             */
/*   Updated: 2025/04/16 16:44:20 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	not_null_ptr(
			unsigned long long ptr, unsigned long long base, char *symbols)
{
	int	count;

	count = 0;
	if (ptr < base)
		return (ft_print_char(symbols[ptr]));
	else
	{
		count = ft_print_number(ptr / base, base, symbols);
		return (count + ft_print_number(ptr % base, base, symbols));
	}
}

int	ft_print_pointer(
		unsigned long long ptr, unsigned long long base, char *symbols)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (not_null_ptr(ptr, base, symbols) + 2);
}
