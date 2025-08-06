/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 06:40:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 06:49:43 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "struct.h"

void	apply_3d_scale(t_control *ctrl, double scale)
{
	int	i;
	int	j;

	if (ctrl == NULL || ctrl->cur_map == NULL)
		return ;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			ctrl->cur_map[i][j].x *= scale;
			ctrl->cur_map[i][j].y *= scale;
			ctrl->cur_map[i][j].z *= scale;
			j++;
		}
		i++;
	}
}
