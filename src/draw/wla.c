/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:08:48 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 17:54:54 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "utils.h"

void	put_pixel_to_image(char *data, int x, int y, int color, int width)
{
	int	index;

	index = (y * width + x) * 4;
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
	data[index + 3] = (color >> 24) & 0xFF;
}

int	blend_colors(int bg_color, int fg_color, double alpha)
{
	int bg_r;
	int bg_g;
	int bg_b;
	int fg_r;
	int fg_g;
	int fg_b;

	bg_r = (bg_color >> 16) & 0xFF;
	bg_g = (bg_color >> 8) & 0xFF;
	bg_b = bg_color & 0xFF;
	fg_r = (fg_color >> 16) & 0xFF;
	fg_g = (fg_color >> 8) & 0xFF;
	fg_b = fg_color & 0xFF;
	int r = (int)((1 - alpha) * bg_r + alpha * fg_r);
	int g = (int)((1 - alpha) * bg_g + alpha * fg_g);
	int b = (int)((1 - alpha) * bg_b + alpha * fg_b);
	return ((r << 16) | (g << 8) | b);
}

void	wla_v(int x0, int y0, int x1, int y1, void *mlx, void *win, void *img)
{
	int		i;
	int		dx;
	int		dy;
	double 	m;
	double	x;
	double	y;
	int		ix;
	int		iy;
	double	dist;

	if (y0 > y1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	int gb_color = 0x000000; // 背景色（黒）
	int fg_color = 0xFFFFFF; // 描画色（白）
	dx = x1 - x0;
	dy = y1 - y0;
	if  (dx != 0)
		m = (double)dy / (double)dx;
	else
		m = 1;
	i = 0;
	while (i <= dy + 1)
	{
		x = x0 + i * m;
		y = y0 + i;
		ix = (int)x;
		iy = (int)y;
		dist = x - ix;
		int blended_color = blend_colors(gb_color, fg_color, dist);
		mlx_pixel_put(mlx, win, ix, iy, 0xFFFFFF);
		mlx_pixel_put(mlx, win, ix + 1, iy, 0xFFFFFF);
		i++;
	}
}

void	wla_h(int x0, int y0, int x1, int y1, void *mlx, void *win, void *img)
{
	int		i;
	int		dx;
	int		dy;
	double 	m;
	double	x;
	double	y;
	int		ix;
	int		iy;
	double	dist;

	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	int gb_color = 0x000000; // 背景色（黒）
	int fg_color = 0xFFFFFF; // 描画色（白）
	dx = x1 - x0;
	dy = y1 - y0;
	if  (dx != 0)
		m = (double)dy / (double)dx;
	else
		m = 1;
	i = 0;
	while (i <= dx + 1)
	{
		x = x0 + i;
		y = y0 + i * m;
		ix = (int)x;
		iy = (int)y;
		dist = y - iy;
		int blended_color = blend_colors(gb_color, fg_color, dist);
		mlx_pixel_put(mlx, win, ix, iy, 0xFFFFFF);
		mlx_pixel_put(mlx, win, ix, iy + 1, 0xFFFFFF);
		i++;
	}
}

void	wla(int x0, int y0, int x1, int y1, void *mlx, void *win, void *img)
{
	int dx;
	int dy;

	dx = x1 - x0;
	dy = y1 - y0;
	if (my_abs(dx) > my_abs(dy))
		wla_h(x0, y0, x1, y1, mlx, win, img);
	else
		wla_v(x0, y0, x1, y1, mlx, win, img);
}

int	expose_hook(void *param)
{
	void **p = (void **)param;
	void *mlx = p[0];
	void *win = p[1];
	void *img = p[2];
	wla(900, 900, 0, 0, mlx, win, img);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	void	*p[2];

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 900, 900, "WLA00");
// 	img = mlx_new_image(mlx, 900, 900);
// 	p[0] = mlx;
// 	p[1] = win;
// 	void	*param[3] = {mlx, win, img};
// 	mlx_expose_hook(win, expose_hook, p);
// 	mlx_loop(mlx);
// 	return (0);
// }
