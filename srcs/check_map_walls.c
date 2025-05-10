/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:42:17 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 15:49:58 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_top_bottom(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
		{
			error_free_map("Error:\nwalls must be closed (1)", map);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_sides(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			error_free_map("Error:\nSide walls must be closed (1)", map);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_game *g)
{
	return (check_top_bottom(g->map, g->map_width, g->map_height)
		&& check_sides(g->map, g->map_width, g->map_height));
}
