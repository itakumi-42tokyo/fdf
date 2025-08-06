/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:08:39 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/20 17:42:32 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// １．calculate the difference in x and y coordinates
// ２．determine the number of steps required
// ３．calculate the increment in x and y coordinates
// ４．draw the pixels by incrementing x and y coordinates
// ５．use mlx_pixel_put to draw each pixel
// ６．handle the case where the line is steep or shallow
// ７．use a loop to iterate through the steps
// ８．round the x and y coordinates to the nearest integer
// ９．use mlx_pixel_put to draw the pixel at the rounded coordinates
// １０．handle the case where the line is vertical or horizontal
// １１．use a function to calculate the absolute value of a number
// １２．use a function to handle the case where the line is steep or shallow
// １３．use a function to handle the case where the line is vertical or horizontal
// １４．use a function to handle the case where the line is steep or shallow
// １５．use a function to handle the case where the line is vertical or horizontal

#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include "struct.h"

static int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void set_pixel(t_control *ctrl, int x, int y, int color)
{
	int    bytes = ctrl->bits_per_pixel / 8;
	char  *dst;

	if (x < 0 || x >= ctrl->win_size_x || y < 0 || y >= ctrl->win_size_y)
		return ;
	dst = ctrl->data_addr + y * ctrl->size_line + x * bytes;
	*(unsigned int *)dst = color;
}

void	dda(int x1, int y1, int x2, int y2, void *mlx, void *win)
{
	int	i;
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps;
	double x_inc, y_inc;
	double x = x1;
	double y = y1;

	steps = (my_abs(dx) > my_abs(dy)) ? my_abs(dx) : my_abs(dy);
	x_inc = dx / (double)steps;
	y_inc = dy / (double)steps;
	i = 0;
	while (i++ <= steps)
	{
		mlx_pixel_put(mlx, win, round(x), round(y), 0xFFFFFF);
		x += x_inc;
		y += y_inc;
	}
}

int	hook_dda(void *param)
{
	void **p = (void **)param;
	void *mlx = p[0];
	void *win = p[1];
	dda(0, 900, 900, 0, mlx, win);
	return (0);
}

// int	main(void)
// {
// 	void *mlx = mlx_init();
// 	void *win = mlx_new_window(mlx, 900, 900, "Hello, World!");
// 	void *param[2] = {mlx, win};
// 	mlx_expose_hook(win, expose_hook, param);
// 	mlx_loop(mlx);
// 	return (0);
// }
