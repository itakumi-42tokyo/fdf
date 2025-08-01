/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:27:00 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/01 16:07:34 by itakumi          ###   ########.fr       */
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

static void	rotate_y(double deg_y, double *x, double *z)
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
	int	i;
	int	j;

	if (ctrl == NULL)
		return (-1);
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			rotate_x(deg_x, &(ctrl->cur_map[i][j].y), &(ctrl->cur_map[i][j].z));
			rotate_y(deg_y, &(ctrl->cur_map[i][j].x), &(ctrl->cur_map[i][j].z));
			rotate_z(deg_z, &(ctrl->cur_map[i][j].x), &(ctrl->cur_map[i][j].y));
			j++;
		}
		i++;
	}
	return (0);
}
