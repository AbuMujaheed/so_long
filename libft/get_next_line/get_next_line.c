/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:11:01 by sojetimi          #+#    #+#             */
/*   Updated: 2025/01/24 20:14:10 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *str, int *err)
{
	int		trvse;
	char	*line;

	if (!str || !*str)
		return (NULL);
	trvse = 0;
	while (str[trvse] && str[trvse] != '\n')
		trvse++;
	if (str[trvse] == '\n')
		trvse++;
	line = (char *)gnl_ft_calloc((trvse + 1), sizeof(char), err);
	if (!line || *err < 0)
		return (*err = -1, NULL);
	gnl_ft_strlcpy(line, str, trvse + 1);
	return (line);
}

static char	*update_static_buffer(char *str, int *err)
{
	int		i;
	char	*new_str;
	size_t	str_len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str_len = gnl_ft_strlen(str + i);
	if (str_len == 0)
		return (free(str), NULL);
	new_str = (char *)gnl_ft_calloc((str_len + 1), sizeof(char), err);
	if (!new_str || *err < 0)
		return (free(str), *err = -1, NULL);
	gnl_ft_strlcpy(new_str, str + i, str_len + 1);
	free(str);
	return (new_str);
}

static void	read_file(int fd, char **str_start, char *tmp, int *err)
{
	int		fd_read;

	fd_read = 42;
	while (!gnl_ft_strchr(tmp, '\n') && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read < 0)
		{
			*err = -1;
			return ;
		}
		tmp[fd_read] = '\0';
		*str_start = gnl_ft_strjoin(*str_start, tmp, err);
		if (*err < 0)
			return ;
	}
}

char	*get_next_line(int fd)
{
	int				err;
	char			*tmp;
	char			*next_line;
	static char		*str_start;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	err = 0;
	tmp = (char *)gnl_ft_calloc(BUFFER_SIZE + 1, sizeof(char), &err);
	if (!tmp || err < 0)
		return (free(str_start), str_start = NULL, NULL);
	read_file(fd, &str_start, tmp, &err);
	if (err < 0)
		return (free(tmp), free(str_start), str_start = NULL, NULL);
	free(tmp);
	next_line = read_line(str_start, &err);
	if (err < 0)
		return (free(next_line), free(str_start), str_start = NULL, NULL);
	str_start = update_static_buffer(str_start, &err);
	if (err < 0)
		return (free(next_line), free(str_start), str_start = NULL, NULL);
	return (next_line);
}
