/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:09:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/01 16:06:00 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "utils.h"

int	persp_proj(t_control *ctrl)
{
	int		i;
	int		j;
	double	x_new;
	double	y_new;
	double	z_new;

	if (ctrl == NULL || ctrl->persp_map == NULL)
		return (-1);
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			int x = ctrl->cur_map[i][j].x;
			int y = ctrl->cur_map[i][j].y;
			int	z = ctrl->cur_map[i][j].z;

			ctrl->persp_map[i][j].persp_x = (x / (z * tan(ctrl->mag_rate)));
			ctrl->persp_map[i][j].persp_y = (y / (z * tan(ctrl->mag_rate)));
			ctrl->persp_map[i][j].color = ctrl->cur_map[i][j].color;
			j++;
		}
		i++;
	}
	ctrl->persp_map[i] = NULL;
	return (0);
}
