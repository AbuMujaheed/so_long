/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:43:32 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/04 19:56:43 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_unreachable(char **map, int *c_left, int *e_left)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				(*c_left)++;
			if (map[i][j] == 'E')
				(*e_left)++;
		}
	}
}

void	check_path(t_game *g)
{
	char	**map_copy;
	int		collectibles_left;
	int		exit_left;

	collectibles_left = 0;
	exit_left = 0;
	map_copy = copy_map(g->map);
	if (!map_copy)
		exit_game(g, "Error:\nFailed to copy map");
	flood_fill(map_copy, g->player_y, g->player_x);
	count_unreachable(map_copy, &collectibles_left, &exit_left);
	free_map(map_copy);
	if (collectibles_left > 0 || exit_left > 0)
		exit_game(g, "Error:\nUnreachable collectibles or exit!");
}
