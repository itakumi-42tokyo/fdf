/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:58:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 19:38:23 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	multipy_4x4_matrix(const double a[4][4], const double b[4][4], double **result)
{
	double	tmp[4][4];
	int		i;
	int		j;
	int		k;

	// なぜ，このような反復構造をしているのだろうか。
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				tmp[i][j] = a[i][k] * b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}

}

int	apply_iso_to_matrix(double **matrix)
{
	const double	iso_matrix[4][4] = \
	{
		{COS_30, -COS_30, 0.0, 0.0},
		{SIN_30, SIN_30, -1, 0.0},
			{0.0, 0.0, 0.0, 0.0},
			{0.0, 0.0, 0.0, 1}
	};
	if (matrix == NULL || *matrix == NULL)
        return (-1);
	// 等角投影の行列はどのような形だろうか。
	// 行列の積
	matrix[0][0] *= iso_matrix[0][0];
	matrix[0][1] *= iso_matrix[0][1];
	matrix[0][2] *= iso_matrix[0][2];
	matrix[1][0] *= iso_matrix[1][0];
	matrix[1][1] *= iso_matrix[1][1];
	matrix[1][2] *= iso_matrix[1][2];
	// ここで、3行目は切り捨てて良いのだろうか。
	// ->同軸次座標系

    return (0);
}

int	iso_proj(t_control *ctrl)
{
    int		i;
	int		j;
    double	x;
	double	y;
	double	z;
    double	iso_x;
	double	iso_y;

    if (ctrl == NULL || ctrl->cur_map == NULL)
        return (-1);
    i = 0;
    while (i < ctrl->map_height)
    {
        j = 0;
        while (j < ctrl->map_width)
        {
            x = ctrl->cur_map[i][j].x;
            y = ctrl->cur_map[i][j].y;
            z = ctrl->cur_map[i][j].z;

            // 標準的な等角投影変換
            // X軸周りに30°回転後、Y軸周りに45°回転
            iso_x = ((x - y)) * COS_30;
            iso_y = ((x + y)) * SIN_30 - z;

            ctrl->iso_map[i][j].iso_x = iso_x;
            ctrl->iso_map[i][j].iso_y = iso_y;
            ctrl->iso_map[i][j].color = ctrl->cur_map[i][j].color;
            j++;
        }
        i++;
    }
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
// 	x_new = (map[i][j]).x * cos(deg_to_rad(45)) + (map[i][j]).z * sin(deg_to_rad(45));
// 	// y_new = (map[i][j]).y;
// 	z_new = -1 * (map[i][j]).x * sin(deg_to_rad(45)) + (map[i][j]).z * cos(deg_to_rad(45));

// 	// x_new = x_new;
// 	y_new = (map[i][j]).y * cos(deg_to_rad(-35.26)) - z_new * sin(deg_to_rad(-35.26));
// 	ctrl->iso_map[i][j].iso_x = round(x_new);
// 	ctrl->iso_map[i][j].iso_y = round(y_new);
// 	j++;
// }
