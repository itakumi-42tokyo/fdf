/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:58:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/01 16:06:01 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "projection.h"
#include "utils.h"

// 方針1. 毎回フリーする Xh
// 方針2. 上書きする（static）を用いて

int	iso_proj(t_control *ctrl)
{
	t_cur_point	**cur_map;
	int 		i;
	int 		j;
	double		x_new;
	double		y_new;
	double		z_new;

	if (ctrl == NULL || ctrl->cur_map == NULL)
		return (-1);
	cur_map = ctrl->cur_map;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		// 修正後の isometric.c の while ループ部分
		while (j < ctrl->map_width)
		{
			// 元の座標を分かりやすい変数に格納
			int x = cur_map[i][j].x;
			int y = cur_map[i][j].y;
			int z = cur_map[i][j].z;
			// 一般的なアイソメトリック投影の公式を使用
			double angle = 0.523599; // 30度をラジアンに変換した値
			x_new = ((x - y)/ sqrt(2)) * cos(angle);
			y_new = ((x + y) / sqrt(2)) * sin(angle) - z;
			ctrl->iso_map[i][j].iso_x = x_new;
			ctrl->iso_map[i][j].iso_y = y_new;
			ctrl->iso_map[i][j].color = cur_map[i][j].color;
			j++;
		}
		i++;
	}
	return (0);
}

// ___OLD___
// while (j < ctrl->map_width)
// {
// 	x_new = (map[i][j]).x * cos(deg_to_rad(45)) + (map[i][j]).z * sin(deg_to_rad(45));
// 	// y_new = (map[i][j]).y;
// 	z_new = -1 * (map[i][j]).x * sin(deg_to_rad(45)) + (map[i][j]).z * cos(deg_to_rad(45));

// 	// x_new = x_new;
// 	y_new = (map[i][j]).y * cos(deg_to_rad(-35.26)) - z_new * sin(deg_to_rad(-35.26));
// 	ctrl->iso_map[i][j].iso_x = round(x_new);
// 	ctrl->iso_map[i][j].iso_y = round(y_new);
// 	j++;
// }
