/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:56:31 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 16:39:33 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_horizontal_walls(t_map_info *g)
{
	int	i;

	i = -1;
	while (++i < g->width)
		if (g->map[0][i] != '1' || g->map[g->height - 1][i] != '1')
			return (0);
	return (1);
}

static int	check_vertical_walls(t_map_info *g)
{
	int	i;

	i = -1;
	while (++i < g->height)
		if (g->map[i][0] != '1' || g->map[i][g->width - 1] != '1')
			return (0);
	return (1);
}

int	check_walls_b(t_map_info *g)
{
	if (!check_horizontal_walls(g))
	{
		error_free_map("Error:\nTop/bottom walls must be closed (1)", g->map);
		return (0);
	}
	if (!check_vertical_walls(g))
	{
		error_free_map("Error:\nSide walls must be closed (1)", g->map);
		return (0);
	}
	return (1);
}
