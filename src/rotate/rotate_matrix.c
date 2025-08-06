/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:29:29 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/28 18:17:24 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <math.h>
#include "utils.h"
#include "struct.h"

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

