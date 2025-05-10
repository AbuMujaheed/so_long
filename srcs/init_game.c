/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:14:54 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 15:50:54 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_image(t_game *g, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(g->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		exit_game(g, "Error:\nLoading image failed.");
}

static void	fill_background(t_game *g, char *data, int size_line, int bpp)
{
	int				x;
	int				y;
	int				width;
	int				height;
	unsigned int	color;

	width = g->map_width * g->tile_size;
	height = g->map_height * g->tile_size;
	color = 0x87CEEB;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			*(unsigned int *)(data + (y * size_line) + (x * (bpp / 8))) = color;
	}
}

static void	create_background(t_game *g)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;

	g->background_img = mlx_new_image(g->mlx,
			g->map_width * g->tile_size, g->map_height * g->tile_size);
	if (!g->background_img)
		exit_game(g, "Error:\nCreating background image failed.");
	data = mlx_get_data_addr(g->background_img, &bpp, &size_line, &endian);
	if (!data)
		exit_game(g, "Error:\nGetting background data failed.");
	fill_background(g, data, size_line, bpp);
}

static void	init_game_variables(t_game *g)
{
	g->player_count = 0;
	g->exit_count = 0;
	g->total_collectibles = 0;
	g->moves = 0;
	g->collected = 0;
}

int	init_game(t_game *game, char *file)
{
	int	win_width;
	int	win_height;

	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "Error:\nInitializing mlx failed.");
	init_game_variables(game);
	game->map = load_map(file, game);
	game->tile_size = 32;
	win_width = game->tile_size * game->map_width;
	win_height = game->tile_size * game->map_height;
	if (!validate_map(game->map, game))
		return (0);
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
		exit_game(game, "Error:\nCreating window failed.");
	create_background(game);
	load_image(game, &game->wall, "textures/wall.xpm");
	load_image(game, &game->floor, "textures/floor.xpm");
	load_image(game, &game->dolphin, "textures/dolphin.xpm");
	load_image(game, &game->fish, "textures/fish.xpm");
	load_image(game, &game->earth, "textures/earth.xpm");
	return (1);
}
