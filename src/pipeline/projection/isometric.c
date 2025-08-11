/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:58:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 03:20:21 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "projection.h"
#include "utils.h"
#include "macro.h"

// 方針1. 毎回フリーする Xh
// 方針2. 上書きする（static）を用いて

// ...existing code...

// 格納するアドレスは各自で確保してもらおう。
// この関数は乗算だけを担当

// 一次元配列として認識されてしまうのか？
int	apply_iso_to_matrix(double matrix[4][4])
{
	const double	matrix_iso[4][4] = {
	{COS_30, -COS_30, 0.0, 0.0},
	{SIN_30, SIN_30, -1.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}};
	double			matrix_cpy[4][4];
	int				i;
	int				j;

	if (matrix == NULL)
		return (-1);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix_cpy[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
	mul_4x4_mat(matrix_iso, matrix_cpy, matrix);
	return (0);
}

// int	main(void)
// {
// 	double	matrix[4][4] = {
// 		{1, 0, 0, 0},
// 		{0, 1, 0, 0},
// 		{0, 0, 1, 0},
// 		{0, 0, 0, 1}
// 	};

// 	int rtn = apply_iso_to_matrix(matrix);
// 	for (int i = 0; i < 4; i++)
// 	{
// 		for(int j = 0; j < 4; j++)
// 		{
// 			printf("%lf ", matrix[i][j]);
// 		}
// 		puts("");
// 	}
// 	return (0);
// }

int	iso_proj(t_control *ctrl)
{
	(void)ctrl;
	return (0);
}
// int	iso_proj(t_control *ctrl)
// {
// 	t_cur_point	**cur_map;
// 	int 		i;
// 	int 		j;
// 	double		x_new;
// 	double		y_new;
// 	double		z_new;

// 	if (ctrl == NULL || ctrl->cur_map == NULL)
// 		return (-1);
// 	cur_map = ctrl->cur_map;
// 	i = 0;
// 	while (i < ctrl->map_height)
// 	{
// 		j = 0;
// 		// 修正後の isometric.c の while ループ部分
// 		while (j < ctrl->map_width)
// 		{
// 			// 元の座標を分かりやすい変数に格納
// 			int x = cur_map[i][j].x;
// 			int y = cur_map[i][j].y;
// 			int z = cur_map[i][j].z;
// 			// 一般的なアイソメトリック投影の公式を使用
// 			double angle = 0.523599; // 30度をラジアンに変換した値
// 			x_new = ((x - y)) * cos(angle);
// 			y_new = ((x + y)) * sin(angle) - z;
// 			ctrl->iso_map[i][j].iso_x = x_new;
// 			ctrl->iso_map[i][j].iso_y = y_new;
// 			ctrl->iso_map[i][j].color = cur_map[i][j].color;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// ___OLD___
// while (j < ctrl->map_width)
// {
// 	x_new =
// (map[i][j]).x * cos(deg_to_rad(45)) + (map[i][j]).z * sin(deg_to_rad(45));
// 	// y_new = (map[i][j]).y;
// 	z_new = -1 * (map[i][j]).x * sin(deg_to_rad(45))
// + (map[i][j]).z * cos(deg_to_rad(45));
// 	// x_new = x_new;
// 	y_new = (map[i][j]).y * cos(deg_to_rad(-35.26))
// - z_new * sin(deg_to_rad(-35.26));
// 	ctrl->iso_map[i][j].iso_x = round(x_new);
// 	ctrl->iso_map[i][j].iso_y = round(y_new);
// 	j++;
// }
