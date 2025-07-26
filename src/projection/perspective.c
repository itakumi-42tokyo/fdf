/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:09:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 20:57:52 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"

int	persp_proj(t_control *ctrl)
{
	int		i;
	int		j;
	double	x_new;
	double	y_new;
	double	z_new;

	if (ctrl == NULL)
		return (-1);
	ctrl->persp_map = malloc(sizeof(t_perspective *) * (ctrl->map_height + 1));
	if (ctrl->persp_map == NULL)
		return (-1);
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		ctrl->persp_map[i] = malloc(sizeof(t_perspective) * ctrl->map_width);
		if (ctrl->persp_map[i] == NULL)
			return (free_2d((void **)ctrl->persp_map), -1);
		while (j < ctrl->map_width)
		{
			int x = ctrl->map[i][j].x;
			int y = ctrl->map[i][j].y;
			int	z = ctrl->map[i][j].z;

			ctrl->persp_map[i][j].persp_x = (x / (z * tan(ctrl->mag_rate)));
			ctrl->persp_map[i][j].persp_y = (y / (z * tan(ctrl->mag_rate)));
			ctrl->persp_map[i][j].color = ctrl->map[i][j].color;
			j++;
		}
		i++;
	}
	ctrl->persp_map[i] = NULL;
	return (0);
}
