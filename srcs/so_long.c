/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:40:04 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 16:29:56 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	expose_hook_wrapper(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	render_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map_info	map_info;
	int			status;

	if (argc != 2)
		error_exit("Use this format: ./so_long <maps/test_maps.ber>");
	map_info = read_map_info(argv[1]);
	check_map_validity(map_info.map);
	status = check_walls_b(&map_info);
	free_map_info(&map_info);
	if (!status)
		return (0);
	if (!init_game(&game, argv[1]))
		exit_game(&game, "OPS");
	render_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, x_close, &game);
	mlx_hook(game.win, Expose, 0, expose_hook_wrapper, &game);
	mlx_loop(game.mlx);
	return (0);
}
