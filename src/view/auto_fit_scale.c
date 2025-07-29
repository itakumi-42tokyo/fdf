/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_fit_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:34:39 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/29 13:31:48 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <math.h>
#include "struct.h"
#include "view.h"
#include "macro.h"

static void calc_bounds_local(t_control *ctrl, int min_xy[2], int max_xy[2])
{
    int i, j;
    min_xy[0] = min_xy[1] =  INT_MAX;
    max_xy[0] = max_xy[1] = -INT_MAX;
	int	ix;
	int iy;
    for (i = 0; i < ctrl->map_height; i++)
        for (j = 0; j < ctrl->map_width; j++)
        {
            // int ix = ctrl->iso_map[i][j].iso_x;
            // int iy = ctrl->iso_map[i][j].iso_y;
			if (PROJ == ISO)
			{
				ix = ctrl->iso_map[i][j].iso_x;
				iy = ctrl->iso_map[i][j].iso_y;
			}
			else if (PROJ == PERSP)
			{
 				ix = ctrl->persp_map[i][j].persp_x;
				iy = ctrl->persp_map[i][j].persp_y;
			}
            if (ix < min_xy[0]) min_xy[0] = ix;
            if (iy < min_xy[1]) min_xy[1] = iy;
            if (ix > max_xy[0]) max_xy[0] = ix;
            if (iy > max_xy[1]) max_xy[1] = iy;
        }
}

void auto_fit_scale(t_control *ctrl, double fit_ratio)
{
    int min_xy[2], max_xy[2];
    calc_bounds_local(ctrl, min_xy, max_xy);
    double w = max_xy[0] - min_xy[0];
    double h = max_xy[1] - min_xy[1];
    if (w <= 0)
		w = 1;
    if (h <= 0)
		h = 1;
    double sx = (ctrl->win_size_x * fit_ratio) / w;
    double sy = (ctrl->win_size_y * fit_ratio) / h;
    ctrl->scale = fmin(sx, sy);
    // 最終的に min_xy もゼロ原点に移してから中央に配置
    ctrl->offset_x = (ctrl->win_size_x - ctrl->scale * w) / 2 - min_xy[0] * ctrl->scale;
    ctrl->offset_y = (ctrl->win_size_y - ctrl->scale * h) / 2 - min_xy[1] * ctrl->scale;
}
