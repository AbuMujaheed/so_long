/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:09:41 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/06 22:11:41 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"

void	gnl_clear_buffer(int fd)
{
	static char	*buffer[1024];

	if (fd >= 0 && fd < 1024)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
}

static void	read_lines_into_map(int fd, char **map, int *height)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	*height = i;
}

static char	**read_map(const char *file, int *height, t_game *g)
{
	int		fd;
	int		rows;
	char	**map;

	rows = count_map_rows(file);
	if (rows <= 0)
		exit_game(g, "Error:\nEmpty map file.");
	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		exit_game(g, "Error:\nMemory allocation failed.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(g, "Error:\nCannot open map file.");
	read_lines_into_map(fd, map, height);
	close(fd);
	return (map);
}

char	**load_map(char *file, t_game *game)
{
	int		fd;
	char	**map;
	int		height;

	check_file_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error:\nCannot open map file.");
	close(fd);
	map = read_map(file, &height, game);
	gnl_clear_buffer(fd);
	if (height == 0)
		error_free_map("Error:\nEmpty map file.", map);
	check_map_validity(map);
	game->map_height = height;
	game->map_width = ft_strlen(map[0]);
	return (map);
}
