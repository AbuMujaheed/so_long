/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:34:09 by sojetimi          #+#    #+#             */
/*   Updated: 2025/04/27 17:09:27 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/ft_printf/ft_printf.h"

void	ft_exit(const char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	error_exit(const char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	error_free_map(const char *msg, char **map)
{
	free_map(map);
	error_exit(msg);
}
