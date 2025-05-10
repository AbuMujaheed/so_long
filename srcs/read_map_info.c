/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:07:28 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 16:31:33 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
}

static void	read_lines_into_map(int fd, char **map, int *height)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (height)
		*height = i;
}

t_map_info	read_map_info(const char *file)
{
	t_map_info	info;
	int			fd;
	int			rows;

	rows = count_map_rows(file);
	if (rows <= 0)
		error_exit("Error:\nEmpty map file.");
	info.map = malloc(sizeof(char *) * (rows + 1));
	if (!info.map)
		error_exit("Error:\nMemory allocation failed.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error:\nCannot open map file.");
	read_lines_into_map(fd, info.map, &info.height);
	close(fd);
	info.map[rows] = NULL;
	if (!info.map[0])
		error_free_map("Error:\nFirst line is empty or invalid.", info.map);
	info.width = ft_strlen(info.map[0]);
	return (info);
}
