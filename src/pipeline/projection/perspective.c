/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:09:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 04:43:52 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "utils.h"
#include "macro.h"

// take 2

static void	init_persp(double mat_persp[4][4], t_control *ctrl)
{
	mat_persp[0][0] = ctrl->camera.focus / ctrl->camera.aspect;
	mat_persp[0][1] = 0;
	mat_persp[0][2] = 0;
	mat_persp[0][3] = 0;
	mat_persp[1][0] = 0;
	mat_persp[1][1] = ctrl->camera.focus;
	mat_persp[1][2] = 0;
	mat_persp[1][3] = 0;
	mat_persp[2][0] = 0;
	mat_persp[2][1] = 0;
	mat_persp[2][2] = (ctrl->camera.far + ctrl->camera.near)
		/ (ctrl->camera.near - ctrl->camera.far);
	mat_persp[2][3] = (2.0 * ctrl->camera.far * ctrl->camera.near)
		/ (ctrl->camera.near - ctrl->camera.far);
	mat_persp[3][0] = 0;
	mat_persp[3][1] = 0;
	mat_persp[3][2] = -1.0;
	mat_persp[3][3] = 0;
}

static void	copy_matrix(double mat_copy[4][4], double mat[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat_copy[i][j] = mat[i][j];
			j++;
		}
		i++;
	}
}

int	apply_persp_to_matrix(double matrix[4][4], t_control *ctrl)
{
	double	matrix_persp[4][4];
	double	matrix_copy[4][4];

	init_persp(matrix_persp, ctrl);
	copy_matrix(matrix_copy, matrix);
	mul_4x4_mat(matrix_persp, matrix_copy, matrix);
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
