/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:18:00 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/06 21:53:42 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_img(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win,
		img, x * g->tile_size, y * g->tile_size);
}

static void	render_tile(t_game *g, int x, int y)
{
	put_img(g, g->floor.img, x, y);
	if (g->map[y][x] == '1')
		put_img(g, g->wall.img, x, y);
	else if (g->map[y][x] == 'P')
	{
		g->player_x = x;
		g->player_y = y;
		put_img(g, g->dolphin.img, x, y);
	}
	else if (g->map[y][x] == 'C')
		put_img(g, g->fish.img, x, y);
	else if (g->map[y][x] == 'E')
		put_img(g, g->earth.img, x, y);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	mlx_put_image_to_window(g->mlx, g->win, g->background_img, 0, 0);
	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
			render_tile(g, x, y);
	}
	render_move_counter(g);
}
