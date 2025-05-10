/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:50:29 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/06 21:28:01 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/ft_printf/ft_printf.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	destroy_images_and_window(t_game *g)
{
	if (g->wall.img)
		mlx_destroy_image(g->mlx, g->wall.img);
	if (g->floor.img)
		mlx_destroy_image(g->mlx, g->floor.img);
	if (g->dolphin.img)
		mlx_destroy_image(g->mlx, g->dolphin.img);
	if (g->fish.img)
		mlx_destroy_image(g->mlx, g->fish.img);
	if (g->earth.img)
		mlx_destroy_image(g->mlx, g->earth.img);
	if (g->background_img)
		mlx_destroy_image(g->mlx, g->background_img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}

void	exit_game(t_game *g, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (!g)
		exit(1);
	if (g->map)
		free_map(g->map);
	if (g->mlx)
		destroy_images_and_window(g);
	exit(1);
}

int	x_close(t_game *g)
{
	exit_game(g, "Window closed");
	return (0);
}
