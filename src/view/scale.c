/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:21:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/23 15:08:17 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <stddef.h>
#include <limits.h>
#include <math.h>
#include "libft.h"
#include "macro.h"
#include "struct.h"

static inline void calc_bounds_iso(t_control *ctrl)
{
	int	i;
	int	j;
	int	min_x0_y1[2];
	int	max_x0_y1[2];

	if (ctrl == NULL)
		return ;
	min_x0_y1[0] = INT_MAX;
	min_x0_y1[1] = INT_MAX;
	max_x0_y1[0] = INT_MIN;
	max_x0_y1[1] = INT_MIN;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			if (min_x0_y1[0] > (ctrl->iso_map[i][j]).iso_x)
				min_x0_y1[0] = (ctrl->iso_map[i][j]).iso_x;
			if (min_x0_y1[1] > (ctrl->iso_map[i][j]).iso_y)
				min_x0_y1[1] = (ctrl->iso_map[i][j]).iso_y;
			if (max_x0_y1[0] < (ctrl->iso_map[i][j]).iso_x)
				max_x0_y1[0] = (ctrl->iso_map[i][j]).iso_x;
			if (max_x0_y1[1] < (ctrl->iso_map[i][j]).iso_y)
				max_x0_y1[1] = (ctrl->iso_map[i][j]).iso_y;
			j++;
		}
		i++;
	}
	ctrl->iso_min_x0_y1[0] = min_x0_y1[0];
	ctrl->iso_min_x0_y1[1] = min_x0_y1[1];
	ctrl->iso_max_x0_y1[0] = max_x0_y1[0];
	ctrl->iso_max_x0_y1[1] = max_x0_y1[1];
}

// XXX
void	debug(t_control *ctrl)
{
	for (int i = 0; i < ctrl->map_height; i++)
	{
		for(int j = 0; j < ctrl->map_width; j++)
		{
			puts("---------------");
			printf("iso_x[%d][%d]: %d\n", i, j, ctrl->iso_map[i][j].iso_x);
			printf("iso_y[%d][%d]: %d\n", i, j, ctrl->iso_map[i][j].iso_y);
		}
	}

}

void	scale(t_control *ctrl)
{
	int		iso_width0_hight1[2];
	double	scale_x0_y1[2];

	calc_bounds_iso(ctrl);
	iso_width0_hight1[0] = ctrl->iso_max_x0_y1[0] - ctrl->iso_min_x0_y1[0];
	iso_width0_hight1[1] = ctrl->iso_max_x0_y1[1] - ctrl->iso_min_x0_y1[1];
	if (iso_width0_hight1[0] <= 0)
		iso_width0_hight1[0] = 1;
	scale_x0_y1[0] = (ctrl->win_size_x * 0.9) / iso_width0_hight1[0];
	if (iso_width0_hight1[1] <= 0)
		iso_width0_hight1[1] = 1;
	scale_x0_y1[1] = (ctrl->win_size_y * 0.9) / iso_width0_hight1[1];
	ctrl->scale = fmin(scale_x0_y1[0], scale_x0_y1[1]);
	ctrl->offset_x = (ctrl->win_size_x / 2) - (iso_width0_hight1[0] / 2);
	ctrl->offset_y = (ctrl->win_size_y / 2) - (iso_width0_hight1[1] / 2);
}
