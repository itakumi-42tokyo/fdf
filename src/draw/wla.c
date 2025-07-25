/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:08:48 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/22 20:35:07 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mlx.h"
#include "utils.h"
#include "struct.h"

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
	char	*data;

	if (y0 > y1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	int gb_color = 0x000000;// background color (black)
	int fg_color = 0xFFFFFF;// foreground color (white)
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
	int gb_color = 0x000000;// background color (black)
	int fg_color = 0xFFFFFF; // foreground color (white)
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

static int	calc_scale(t_control *ctrl, int point, bool x)
{
	int scaled;

	if (ctrl == NULL)
		return (-1);
	if (x == true)
	{
		scaled = (int)((point - ctrl->iso_min_x0_y1[0]) * ctrl->scale + (ctrl->win_size_x * 0.05));
	}
	else
	{
		scaled = (int)((point - ctrl->iso_min_x0_y1[1]) * ctrl->scale + (ctrl->win_size_y * 0.05));
	}
	// printf("-------------\n");
	// printf("point: %d\n", point);
	// printf("ctrl->iso_min_x0_y1: %d\n", ctrl->iso_min_x0_y1[0]);
	// printf("y1: %d\n", ctrl->iso_min_x0_y1[1]);
	// printf("ctrl->scale: %f\n", ctrl->scale);
	// printf("ctrl->win_size_x: %d\n", ctrl->win_size_x);
	// printf("scaled: %d\n", scaled);
	return (scaled);
}

int	hook_wla(const void *param)
{
	t_control	**ctrl;
	int			i;
	int			j;
	int			x0;
	int			y0;
	int			x1;
	int			y1;

	ctrl = (t_control **)param;
	i = 0;
	while (i < (*ctrl)->map_height)
	{
		j = 0;
		while (j < (*ctrl)->map_width)
		{
			if (j + 1 < (*ctrl)->map_width)
			{
				x0 = calc_scale(*ctrl, (*ctrl)->iso_map[i][j].iso_x, true) + (*ctrl)->offset_x - 500;
				y0 = calc_scale(*ctrl, (*ctrl)->iso_map[i][j].iso_y, false) + (*ctrl)->offset_y - 500;
				x1 = calc_scale(*ctrl, (*ctrl)->iso_map[i][j + 1].iso_x, true) + (*ctrl)->offset_x - 500;
				y1 = calc_scale(*ctrl, (*ctrl)->iso_map[i][j + 1].iso_y, false) + (*ctrl)->offset_y - 500;
				// printf("----------\n");
				// printf("x0:%d; y0:%d\n", x0, y0);
				// printf("x1:%d; y1:%d\n", x1, y1);
				wla(x0, y0, x1, y1, (*ctrl)->mlx, (*ctrl)->win, (*ctrl)->img);
			}
			if (i + 1 < (*ctrl)->map_height)
			{
				x0 = calc_scale(*ctrl, (*ctrl)->iso_map[i][j].iso_x, true) + (*ctrl)->offset_x - 500;
				y0 = calc_scale(*ctrl, (*ctrl)->iso_map[i][j].iso_y, false) + (*ctrl)->offset_y - 500;
				x1 = calc_scale(*ctrl, (*ctrl)->iso_map[i + 1][j].iso_x, true) + (*ctrl)->offset_x - 500;
				y1 = calc_scale(*ctrl, (*ctrl)->iso_map[i + 1][j].iso_y, false) + (*ctrl)->offset_y - 500;
				// printf("----------\n");
				// printf("x0:%d; y0:%d\n", x0, y0);
				// printf("x1:%d; y1:%d\n", x1, y1);
				wla(x0, y0, x1, y1, (*ctrl)->mlx, (*ctrl)->win, (*ctrl)->img);
			}
			j++;
		}
		i++;
	}
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
// 	mlx_expose_hook(win, hook_wla, p);
// 	mlx_loop(mlx);
// 	return (0);
// }
