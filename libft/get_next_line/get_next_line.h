/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:10:52 by sojetimi          #+#    #+#             */
/*   Updated: 2025/01/26 16:42:25 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*gnl_ft_strchr(const char *s, int c);
char	*gnl_ft_strjoin(char *start, char *buff, int *err);
void	*gnl_ft_calloc(size_t count, size_t size, int *err);
size_t	gnl_ft_strlen(const char *str);
size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
