/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:29:29 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 03:15:49 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include "struct.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	init_cos(double cos_xyz[3],
		double deg_x, double deg_y, double deg_z)
{
	cos_xyz[0] = cos(deg_to_rad(deg_x));
	cos_xyz[1] = cos(deg_to_rad(deg_y));
	cos_xyz[2] = cos(deg_to_rad(deg_z));
}

static void	init_sin(double sin_xyz[3],
		double deg_x, double deg_y, double deg_z)
{
	sin_xyz[0] = sin(deg_to_rad(deg_x));
	sin_xyz[1] = sin(deg_to_rad(deg_y));
	sin_xyz[2] = sin(deg_to_rad(deg_z));
}

static void	copy_matrix(double matrix_copy[4][4], double matrix_src[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix_copy[i][j] = matrix_src[i][j];
			j++;
		}
		i++;
	}
}

static void	init_rot(double rot[4][4], double cos_xyz[3], double sin_xyz[3])
{
	rot[0][0] = cos_xyz[1] * cos_xyz[2];
	rot[0][1] = -cos_xyz[1] * sin_xyz[2];
	rot[0][2] = sin_xyz[1];
	rot[0][3] = 0.0;
	rot[1][0] = sin_xyz[0] * sin_xyz[1] * cos_xyz[2] + cos_xyz[0] * sin_xyz[2];
	rot[1][1] = -sin_xyz[0] * sin_xyz[1] * sin_xyz[2] + cos_xyz[0] * cos_xyz[2];
	rot[1][2] = -sin_xyz[0] * cos_xyz[1];
	rot[1][3] = 0.0;
	rot[2][0] = -cos_xyz[0] * sin_xyz[1] * cos_xyz[2] + sin_xyz[0] * sin_xyz[2];
	rot[2][1] = cos_xyz[0] * sin_xyz[1] * sin_xyz[2] + sin_xyz[0] * cos_xyz[2];
	rot[2][2] = cos_xyz[0] * cos_xyz[1];
	rot[2][3] = 0.0;
	rot[3][0] = 0.0;
	rot[3][1] = 0.0;
	rot[3][2] = 0.0;
	rot[3][3] = 1.0;
}

void	apply_rotate_matrix(double matrix[4][4],
			double deg_x, double deg_y, double deg_z)
{
	double	cos_xyz[3];
	double	sin_xyz[3];
	double	rot[4][4];
	double	prev[4][4];

	if (matrix == NULL)
		return ;
	init_cos(cos_xyz, deg_x, deg_y, deg_z);
	init_sin(sin_xyz, deg_x, deg_y, deg_z);
	init_rot(rot, cos_xyz, sin_xyz);
	copy_matrix(prev, matrix);
	mul_4x4_mat(rot, prev, matrix);
}

// int	calc_matrix(t_control *ctrl, double deg_x, double deg_y, double deg_z)
// {
// 	(void)ctrl;
// 	(void)deg_x;
// 	(void)deg_y;
// 	(void)deg_z;
// 	return (0);
// }
// content!!
	// double	matrix[3][3];
	// double	cos_x;
	// double	cos_y;
	// double	cos_z;
	// double	sin_x;
	// double	sin_y;
	// double	sin_z;
	// int		i;
	// int		j;
	// double	x;
	// double	y;
	// double	z;

	// cos_x = cos(deg_to_rad(deg_x));
	// cos_y = cos(deg_to_rad(deg_y));
	// cos_z = cos(deg_to_rad(deg_z));
	// sin_x = sin(deg_to_rad(deg_x));
	// sin_y = sin(deg_to_rad(deg_y));
	// sin_z = sin(deg_to_rad(deg_z));
	// matrix[0][0] = cos_y * cos_z;
	// matrix[0][1] = -cos_y * sin_z;
	// matrix[0][2] = sin_y;
	// matrix[1][0] = sin_x * sin_y * cos_z + cos_x * sin_z;
	// matrix[1][1] = -sin_x * sin_y * sin_z + cos_x * cos_z;
	// matrix[1][2] = -sin_x * cos_y;
	// matrix[2][0] = -cos_x * sin_y * cos_z + sin_x * sin_z;
	// matrix[2][1] = cos_x * sin_y * sin_z + sin_x * cos_z;
	// matrix[2][2] = cos_x * cos_y;
	// while (i < ctrl->map_height)
	// {
	// 	j = 0;
	// 	while (j < ctrl->map_width)
	// 	{
	// 		x = ctrl->map[i][j].x;
	// 		j++;
	// 	}
	// 	i++;
	// }
