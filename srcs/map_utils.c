/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:44:40 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/06 21:28:55 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../libft/get_next_line/get_next_line.h"

int	count_map_rows(const char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

void	check_file_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		error_exit("Error:\nFile must have .ber extension.");
}

void	check_map_validity(char **map)
{
	int		i;
	char	*line;
	char	*newline;

	i = 0;
	while (map[i])
	{
		line = map[i];
		newline = ft_strchr(line, '\n');
		if (newline)
			*newline = '\0';
		if (line[0] == '\0')
			error_free_map("Error:\nEmpty line in map.", map);
		i++;
	}
}
