/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:27:00 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/29 19:34:13 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <math.h>
#include "struct.h"
#include "projection.h"

int	calc_euler(t_control *ctrl)
{

}

//
void	rotate_x(double *x, double *y, double *z, int angle)
{
	double	prev_y;
	double	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(deg_to_rad((double)angle)) - prev_z * sin(deg_to_rad((double)angle));
	*z = prev_y * sin(deg_to_rad((double)angle)) + prev_z * cos(deg_to_rad((double)angle));
}

void	rotate_y(double *x, double *y, double *z, int angle)
{
	double	prev_x;
	double	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(deg_to_rad((double)angle)) + prev_z * sin(deg_to_rad((double)angle));
	*z = -prev_x * sin(deg_to_rad((double)angle)) + prev_z * cos(deg_to_rad((double)angle));
}

void	rotate_z(double *x, double *y, double *z, int angle)
{
	double	prev_y;
	double	prev_x;

	prev_y = *y;
	prev_x = *x;
	*y = prev_x * cos(deg_to_rad((double)angle)) - prev_y * sin(deg_to_rad((double)angle));
	*x = prev_x * sin(deg_to_rad((double)angle)) + prev_y * cos(deg_to_rad((double)angle));
}
