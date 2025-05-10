/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:19:02 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/03 19:34:21 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/ft_printf/ft_printf.h"

static void	move_player(t_game *g, int new_x, int new_y)
{
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'E'
				&& g->collected != g->total_collectibles)
		return ;
	if (g->map[new_y][new_x] == 'C')
	{
		g->collected++;
		g->map[new_y][new_x] = '0';
	}
	if (g->map[new_y][new_x] == 'E'
				&& g->collected == g->total_collectibles)
	{
		ft_printf("Moves: %d\n", g->moves + 1);
		exit_game(g, "You win!");
	}
	g->map[g->player_y][g->player_x] = '0';
	g->map[new_y][new_x] = 'P';
	g->player_x = new_x;
	g->player_y = new_y;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	render_map(g);
}

int	handle_input(int keycode, t_game *g)
{
	int	new_x;
	int	new_y;

	new_x = g->player_x;
	new_y = g->player_y;
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		new_y--;
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		new_y++;
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		new_x--;
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		new_x++;
	else if (keycode == XK_Escape)
		exit_game(g, "Game exited");
	else
		return (0);
	if (new_x >= 0 && new_x < g->map_width
		&& new_y >= 0 && new_y < g->map_height)
		move_player(g, new_x, new_y);
	return (0);
}
