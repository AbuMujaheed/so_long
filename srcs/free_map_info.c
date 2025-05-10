/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:58:26 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 15:58:29 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map_info(t_map_info *info)
{
	int	i;

	i = 0;
	if (!info || !info->map)
		return ;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	info->map = NULL;
}
