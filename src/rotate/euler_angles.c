/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:27:00 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/01 23:09:50 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <math.h>
#include "struct.h"
#include "utils.h"

//
static void	rotate_x(double deg_x, double *y, double *z)
{
	double	prev_y;
	double	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(deg_to_rad(deg_x)) - prev_z * sin(deg_to_rad(deg_x));
	*z = prev_y * sin(deg_to_rad(deg_x)) + prev_z * cos(deg_to_rad(deg_x));
}

static void	rotate_y(double deg_y, double *z, double *x)
{
	double	prev_x;
	double	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(deg_to_rad(deg_y)) + prev_z * sin(deg_to_rad(deg_y));
	*z = -prev_x * sin(deg_to_rad(deg_y)) + prev_z * cos(deg_to_rad(deg_y));
}

static void	rotate_z(double deg_z, double *x, double *y)
{
	double	prev_y;
	double	prev_x;

	prev_y = *y;
	prev_x = *x;
	*y = prev_x * cos(deg_to_rad(deg_z)) - prev_y * sin(deg_to_rad(deg_z));
	*x = prev_x * sin(deg_to_rad(deg_z)) + prev_y * cos(deg_to_rad(deg_z));
}



int	calc_euler(t_control *ctrl, double deg_x, double deg_y, double deg_z)
{
	int		i;
	int		j;
	double center_x;
	double center_y;
	double x, y, z;
		if (ctrl == NULL)
			return (-1);
	center_x = (ctrl->map_width - 1) / 2.0;
	center_y = (ctrl->map_height - 1) / 2.0;
		// 回転の中心に移動
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			x = ctrl->cur_map[i][j].x;
			y = ctrl->cur_map[i][j].y;
			z = ctrl->cur_map[i][j].z;

			x -= center_x;
			y -= center_y;

			rotate_x(deg_x, &y, &z);
			rotate_y(deg_y, &z, &x);
			rotate_z(deg_z, &x, &y);

			x += center_x;
			y += center_y;

			ctrl->cur_map[i][j].x = x;
			ctrl->cur_map[i][j].y = y;
			ctrl->cur_map[i][j].z = z;
			ctrl->cur_map[i][j].color = ctrl->map[i][j].color;
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < ctrl->map_height)
	// {
	// 	j = 0;
	// 	while (j < ctrl->map_width)
	// 	{
	// 		rotate_x(deg_x, &(ctrl->cur_map[i][j].y), &(ctrl->cur_map[i][j].z));
	// 		rotate_y(deg_y, &(ctrl->cur_map[i][j].x), &(ctrl->cur_map[i][j].z));
	// 		rotate_z(deg_z, &(ctrl->cur_map[i][j].x), &(ctrl->cur_map[i][j].y));
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (0);
}
