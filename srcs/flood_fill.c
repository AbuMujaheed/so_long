/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:11:52 by sojetimi          #+#    #+#             */
/*   Updated: 2025/04/29 18:36:52 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (y < 0 || x < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'V')
		return ;
	if (map[y][x] != '0' && map[y][x] != 'C'
		&& map[y][x] != 'E' && map[y][x] != 'P')
		return ;
	map[y][x] = 'V';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}
