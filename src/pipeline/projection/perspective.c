/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:09:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 17:24:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "utils.h"
#include "macro.h"

// take 3

// typedef struct s_matrix
// {
//     double m[4][4];
// }	t_matrix;

// // 4x4行列の掛け算
// void multiply_matrix(t_matrix *result, t_matrix *a, t_matrix *b)
// {
//     int i, j, k;
//     for (i = 0; i < 4; i++) {
//         for (j = 0; j < 4; j++) {
//             result->m[i][j] = 0;
//             for (k = 0; k < 4; k++) {
//                 result->m[i][j] += a->m[i][k] * b->m[k][j];
//             }
//         }
//     }
// }

// // ビュー行列（カメラ座標系）の生成
// void create_view_matrix(t_matrix *view, t_camera *cam)
// {
//     double forward_x = cam->look_x - cam->pos_x;
//     double forward_y = cam->look_y - cam->pos_y;
//     double forward_z = cam->look_z - cam->pos_z;

//     // 正規化
//     double len = sqrt(forward_x * forward_x + forward_y * forward_y + forward_z * forward_z);
//     forward_x /= len; forward_y /= len; forward_z /= len;

//     // 右ベクトル = forward × up
//     double right_x = forward_y * cam->up_z - forward_z * cam->up_y;
//     double right_y = forward_z * cam->up_x - forward_x * cam->up_z;
//     double right_z = forward_x * cam->up_y - forward_y * cam->up_x;

//     len = sqrt(right_x * right_x + right_y * right_y + right_z * right_z);
//     right_x /= len; right_y /= len; right_z /= len;

//     // 上ベクトル = right × forward
//     double up_x = right_y * forward_z - right_z * forward_y;
//     double up_y = right_z * forward_x - right_x * forward_z;
//     double up_z = right_x * forward_y - right_y * forward_x;

//     // ビュー行列の構築
//     view->m[0][0] = right_x;   view->m[0][1] = up_x;   view->m[0][2] = -forward_x; view->m[0][3] = 0;
//     view->m[1][0] = right_y;   view->m[1][1] = up_y;   view->m[1][2] = -forward_y; view->m[1][3] = 0;
//     view->m[2][0] = right_z;   view->m[2][1] = up_z;   view->m[2][2] = -forward_z; view->m[2][3] = 0;
//     view->m[3][0] = -(right_x * cam->pos_x + right_y * cam->pos_y + right_z * cam->pos_z);
//     view->m[3][1] = -(up_x * cam->pos_x + up_y * cam->pos_y + up_z * cam->pos_z);
//     view->m[3][2] = forward_x * cam->pos_x + forward_y * cam->pos_y + forward_z * cam->pos_z;
//     view->m[3][3] = 1;
// }

// // 透視投影行列の生成
// void create_perspective_matrix(t_matrix *proj, t_camera *cam)
// {
//     double fov_rad = cam->fov * M_PI / 180.0;
//     double f = 1.0 / tan(fov_rad / 2.0);
//     double near_far = cam->near - cam->far;

//     // 透視投影行列
//     proj->m[0][0] = f / cam->aspect; proj->m[0][1] = 0; proj->m[0][2] = 0; proj->m[0][3] = 0;
//     proj->m[1][0] = 0; proj->m[1][1] = f; proj->m[1][2] = 0; proj->m[1][3] = 0;
//     proj->m[2][0] = 0; proj->m[2][1] = 0; proj->m[2][2] = (cam->far + cam->near) / near_far; proj->m[2][3] = -1;
//     proj->m[3][0] = 0; proj->m[3][1] = 0; proj->m[3][2] = (2 * cam->far * cam->near) / near_far; proj->m[3][3] = 0;
// }

// // 点を4x4行列で変換
// void transform_point(double *x, double *y, double *z, double *w, t_matrix *matrix)
// {
//     double orig_x = *x, orig_y = *y, orig_z = *z, orig_w = *w;

//     *x = matrix->m[0][0] * orig_x + matrix->m[0][1] * orig_y + matrix->m[0][2] * orig_z + matrix->m[0][3] * orig_w;
//     *y = matrix->m[1][0] * orig_x + matrix->m[1][1] * orig_y + matrix->m[1][2] * orig_z + matrix->m[1][3] * orig_w;
//     *z = matrix->m[2][0] * orig_x + matrix->m[2][1] * orig_y + matrix->m[2][2] * orig_z + matrix->m[2][3] * orig_w;
//     *w = matrix->m[3][0] * orig_x + matrix->m[3][1] * orig_y + matrix->m[3][2] * orig_z + matrix->m[3][3] * orig_w;
// }

// // ...existing code...
// int	persp_proj(t_control *ctrl)
// {
//     int i, j;
//     t_camera camera;
//     t_matrix view_matrix, proj_matrix, mvp_matrix, temp_matrix;
//     double x, y, z, w;
//     double screen_x, screen_y;

//     if (ctrl == NULL || ctrl->persp_map == NULL)
//         return (-1);

//     // カメラの設定
//     camera.pos_x = 0; camera.pos_y = 0; camera.pos_z = 1000;  // カメラ位置
//     camera.look_x = ctrl->map_width / 2; camera.look_y = ctrl->map_height / 2; camera.look_z = 0; // 注視点
//     camera.up_x = 0; camera.up_y = 1; camera.up_z = 0;        // アップベクトル
//     camera.fov = 45.0;                                         // 視野角
//     camera.aspect = (double)ctrl->win_size_x / ctrl->win_size_y; // アスペクト比
//     camera.near = 1.0; camera.far = 2000.0;                   // クリッピング

//     // 行列の生成
//     create_view_matrix(&view_matrix, &camera);
//     create_perspective_matrix(&proj_matrix, &camera);
//     multiply_matrix(&mvp_matrix, &proj_matrix, &view_matrix);

//     i = 0;
//     while (i < ctrl->map_height)
//     {
//         j = 0;
//         while (j < ctrl->map_width)
//         {
//             // ワールド座標
//             x = ctrl->cur_map[i][j].x;
//             y = ctrl->cur_map[i][j].y;
//             z = ctrl->cur_map[i][j].z;
//             w = 1.0;

//             // MVP変換（Model-View-Projection）
//             transform_point(&x, &y, &z, &w, &mvp_matrix);

//             // 透視除算
//             if (w != 0.0)
//             {
//                 x /= w;
//                 y /= w;
//                 z /= w;
//             }

//             // NDC（-1〜1）からスクリーン座標への変換
//             screen_x = (x + 1.0) * ctrl->win_size_x / 2.0;
//             screen_y = (1.0 - y) * ctrl->win_size_y / 2.0;  // Yを反転

//             ctrl->persp_map[i][j].persp_x = screen_x;
//             ctrl->persp_map[i][j].persp_y = screen_y;
//             ctrl->persp_map[i][j].color = ctrl->cur_map[i][j].color;

//             j++;
//         }
//         i++;
//     }
//     return (0);
// }

// take 2

int	apply_persp_to_matrix(double marix[4][4])
{
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

// 			ctrl->persp_map[i][j].persp_x = (x / (z * tan(deg_torad((ctrl->mag_rate)))));
// 			ctrl->persp_map[i][j].persp_y = (y / (z * tan(deg_to_rad(ctrl->mag_rate))));
// 			ctrl->persp_map[i][j].color = ctrl->cur_map[i][j].color;
// 			j++;
// 		}
// 		i++;
// 	}
// 	ctrl->persp_map[i] = NULL;
// 	return (0);
// }
