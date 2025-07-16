/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:08:39 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/16 23:02:43 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// １．直線の方程式を求める。
// ２．ラスタライズする
// ３．1 < 1 > で場合分けする

#include "../../lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
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

int	expose_hook(void *param)
{
	void **p = (void **)param;
	void *mlx = p[0];
	void *win = p[1];
	dda(0, 900, 900, 0, mlx, win);
	return (0);
}

int	main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 900, 900, "Hello, World!");
	void *param[2] = {mlx, win};
	mlx_expose_hook(win, expose_hook, param);
	mlx_loop(mlx);
	return (0);
}
