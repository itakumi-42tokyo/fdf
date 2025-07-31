/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:26:53 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/31 21:35:21 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include "struct.h"
#include "utils.h"

t_cur_point	**copy_map(t_control	*ctrl)
{
	t_cur_point		**cur_map;
	int				i;
	int				j;

	if (ctrl == NULL)
		return (NULL);
	cur_map = malloc(sizeof(t_cur_point *) * (ctrl->map_height + 1));
	if (cur_map == NULL)
		return (NULL);
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		cur_map[i] = malloc(sizeof(t_cur_point) * ctrl->map_width);
		if (cur_map[i] == NULL)
			return (free_2d((void **)cur_map), NULL); // FIXME
		while (j < ctrl->map_width)
		{
			cur_map[i][j].x = ctrl->map[i][j].x;
			cur_map[i][j].y = ctrl->map[i][j].y;
			cur_map[i][j].z = ctrl->map[i][j].z;
			cur_map[i][j].color = ctrl->map[i][j].color;
			j++;
		}
		i++;
	}
	cur_map[i] = NULL;
	return (cur_map);
}
