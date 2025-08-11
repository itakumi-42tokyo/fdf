/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:09:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 03:20:44 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "utils.h"
#include "macro.h"

// take 2

int	apply_persp_to_matrix(double matrix[4][4])
{
	(void)matrix;
	return (0);
}

// int	persp_proj(t_control *ctrl)
// {
//     int		i;
//     int		j;
//     double	x, y, z;
//     double	focal_length;
//     double	camera_distance;

//     if (ctrl == NULL || ctrl->persp_map == NULL)
//         return (-1);

//     focal_length = 500.0;  // 焦点距離を固定値で設定
//     camera_distance = 2000.0;  // カメラ距離

//     i = 0;
//     while (i < ctrl->map_height)
//     {
//         j = 0;
//         while (j < ctrl->map_width)
//         {
//             x = ctrl->cur_map[i][j].x;
//             y = ctrl->cur_map[i][j].y;
//             z = ctrl->cur_map[i][j].z + camera_distance;

//             if (z > 1.0)
//             {
//                 ctrl->persp_map[i][j].persp_x = (x * focal_length) / z;
//                 ctrl->persp_map[i][j].persp_y = (y * focal_length) / z;
//             }
//             else
//             {
//                 ctrl->persp_map[i][j].persp_x = x * focal_length;
//                 ctrl->persp_map[i][j].persp_y = y * focal_length;
//             }
//             ctrl->persp_map[i][j].color = ctrl->cur_map[i][j].color;
//             j++;
//         }
//         i++;
//     }
//     return (0);
// }

// (take 1)

// int	persp_proj(t_control *ctrl)
// {
// 	int		i;
// 	int		j;
// 	double	x;
// 	double	y;
// 	double	z;

// 	if (ctrl == NULL || ctrl->persp_map == NULL)
// 		return (-1);
// 	i = 0;
// 	while (i < ctrl->map_height)
// 	{
// 		j = 0;
// 		while (j < ctrl->map_width)
// 		{
// 			x = ctrl->cur_map[i][j].x;
// 			y = ctrl->cur_map[i][j].y;
// 			z = ctrl->cur_map[i][j].z;

// 			ctrl->persp_map[i][j].persp_x =
	// (x / (z * tan(deg_torad((ctrl->mag_rate)))));
// 			ctrl->persp_map[i][j].persp_y =
// (y / (z * tan(deg_to_rad(ctrl->mag_rate))));
// 			ctrl->persp_map[i][j].color = ctrl->cur_map[i][j].color;
// 			j++;
// 		}
// 		i++;
// 	}
// 	ctrl->persp_map[i] = NULL;
// 	return (0);
// }
