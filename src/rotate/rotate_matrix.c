/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:29:29 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 18:45:24 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <unistd.h>
#include <math.h>
#include "utils.h"
#include "struct.h"

// 回転具用列と
double	**create_rotate_matrix(t_control *ctrl, double deg_x, double deg_y, double deg_z)
{
	double	**matrix;
	int		i;
	double	cos_x;
	double	cos_y;
	double	cos_z;
	double	sin_x;
	double	sin_y;
	double	sin_z;

	if (ctrl == NULL)
		return (NULL);
	matrix = malloc(sizeof(double *) * 5);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < 5)
	{
		matrix[i] = malloc(sizeof(double) * 5);
		if (matrix[i] == NULL)
			return (free_2d((void **)matrix), NULL);
		i++;
	}
	cos_x = cos(deg_to_rad(deg_x));
	cos_y = cos(deg_to_rad(deg_y));
	cos_z = cos(deg_to_rad(deg_z));
	sin_x = sin(deg_to_rad(deg_x));
	sin_y = sin(deg_to_rad(deg_y));
	sin_z = sin(deg_to_rad(deg_z));
	matrix[0][0] = cos_y * cos_z;
	matrix[0][1] = -cos_y * sin_z;
	matrix[0][2] = sin_y;
	matrix[0][3] = 1;
	matrix[0][4] = 0;
	matrix[1][0] = sin_x * sin_y * cos_z + cos_x * sin_z;
	matrix[1][1] = -sin_x * sin_y * sin_z + cos_x * cos_z;
	matrix[1][2] = -sin_x * cos_y;
	matrix[1][3] = 1;
	matrix[1][4] = 0;
	matrix[2][0] = -cos_x * sin_y * cos_z + sin_x * sin_z;
	matrix[2][1] = cos_x * sin_y * sin_z + sin_x * cos_z;
	matrix[2][2] = cos_x * cos_y;
	matrix[2][3] = 1;
	matrix[2][4] = 0;
	matrix[3][0] = 1;
	matrix[3][1] = 1;
	matrix[3][2] = 1;
	matrix[3][3] = 1;
	matrix[3][4] = 0;
	matrix[4] = NULL;
	return (matrix);
}

// 入力の行列に対して、回転操作の行列計算をかけてくれるような関数。
int	calc_matrix(t_control *ctrl, double deg_x, double deg_y, double deg_z)
{
	double	matrix[3][3];
	double	cos_x;
	double	cos_y;
	double	cos_z;
	double	sin_x;
	double	sin_y;
	double	sin_z;
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;

	cos_x = cos(deg_to_rad(deg_x));
	cos_y = cos(deg_to_rad(deg_y));
	cos_z = cos(deg_to_rad(deg_z));
	sin_x = sin(deg_to_rad(deg_x));
	sin_y = sin(deg_to_rad(deg_y));
	sin_z = sin(deg_to_rad(deg_z));

	matrix[0][0] = cos_y * cos_z;
	matrix[0][1] = -cos_y * sin_z;
	matrix[0][2] = sin_y;
	matrix[1][0] = sin_x * sin_y * cos_z + cos_x * sin_z;
	matrix[1][1] = -sin_x * sin_y * sin_z + cos_x * cos_z;
	matrix[1][2] = -sin_x * cos_y;
	matrix[2][0] = -cos_x * sin_y * cos_z + sin_x * sin_z;
	matrix[2][1] = cos_x * sin_y * sin_z + sin_x * cos_z;
	matrix[2][2] = cos_x * cos_y;

	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			x = ctrl->map[i][j].x;
			j++;
		}
		i++;
	}
}
