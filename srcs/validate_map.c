/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:20:00 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 15:23:27 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	parse_tile(char tile, int x, int y, t_game *g)
{
	if (tile != '0' && tile != '1' && tile != 'C' && tile != 'E' && tile != 'P')
		exit_game(g, "Error:\nInvalid character in map");
	if (tile == 'P')
	{
		g->player_x = x;
		g->player_y = y;
		g->player_count++;
	}
	if (g->exit_count > 1)
		exit_game(g, "Error:\nIncorrect exit count in map");
	if (tile == 'E')
		g->exit_count++;
	if (tile == 'C')
		g->total_collectibles++;
}

static void	parse_map(char **map, t_game *g)
{
	int	x;
	int	y;
	int	width;

	y = 0;
	width = ft_strlen(map[0]);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			parse_tile(map[y][x], x, y, g);
			x++;
		}
		if (x != width)
			exit_game(g, "Error:\nMap is not rectangular");
		y++;
	}
	g->map_width = width;
	g->map_height = y;
}

int	validate_map(char **map, t_game *g)
{
	g->map_width = 0;
	g->map_height = 0;
	parse_map(map, g);
	if (g->player_count != 1 || g->exit_count == 0
		|| g->total_collectibles == 0)
		exit_game(g, "Error:\nincorrect number of P, path, or collectibles");
	if (check_walls(g) == 0)
		return (0);
	check_path(g);
	return (1);
}
