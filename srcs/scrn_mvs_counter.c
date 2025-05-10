/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_mvs_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:44:30 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/06 21:57:03 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"

void	render_move_counter(t_game *g)
{
	char	*counter_str;
	char	*display;

	counter_str = ft_itoa(g->moves);
	if (!counter_str)
		exit_game(g, "Error:\nCounter malloc failed");
	display = ft_strjoin("Moves: ", counter_str);
	free(counter_str);
	if (!display)
		exit_game(g, "Error:\nDisplay malloc failed");
	mlx_string_put(g->mlx, g->win, 10, 20, 0xFFFFFF, display);
	free(display);
}
