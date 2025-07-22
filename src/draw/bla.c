/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:22 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/22 22:53:28 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <stdlib.h>
#include "mlx.h"
#include "struct.h"
#include "utils.h"

void	bla_h(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	int		dx;
	int		dy;
	int		dir;
	int		y;
	int		i;
	int		p;

	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	if (dx != 0)
	{
		y = y0;
		i = 0;
		p = 2*dy - dx;
		while (i <= dx + 1)
		{
			mlx_pixel_put(mlx, win, x0 + i, y, 0xFFFFFF);
			if (p >= 0)
			{
				y += dir;
				p = p + 2*dy - 2*dx*(1);
			}
			else
				p = p + 2*dy - 2*dx*(0);
			i++;
		}
	}
}

void	bla_v(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	int		dx;
	int		dy;
	int		dir;
	int		x;
	int		i;
	int		p;

	if (y0 > y1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	if (dy != 0)
	{
		x = x0;
		i = 0;
		p = 2*dx - dy;
		while (i <= dy + 1)
		{
			mlx_pixel_put(mlx, win, x, y0 + i, 0xFFFFFF);
			if (p >= 0)
			{
				x += dir;
				p = p - 2*dy;
			}
			p = p + 2*dx;
			i++;
		}
	}
}

void	bla(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	int	dx;
	int	dy;

	dx = x1 - x0;
	dy = y1 - y0;
	if (my_abs(dx) > my_abs(dy))
		bla_h(x0, y0, x1, y1, mlx, win);
	else
		bla_v(x0, y0, x1, y1, mlx, win);
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

int	hook_bla(void *param)
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
				bla(x0, y0, x1, y1, (*ctrl)->mlx, (*ctrl)->win);
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
				bla(x0, y0, x1, y1, (*ctrl)->mlx, (*ctrl)->win);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// int	hook_bla(void *param)
// {
//     t_control *ctrl = (t_control *)param;
//     bla(10, 800, 800, 10, ctrl->mlx, ctrl->win);
//     return (0);
// }

// int	main(void)
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 900, 900, "win0");
//     t_control ctrl = {mlx, win, NULL};
//     mlx_expose_hook(win, hook_bla, &ctrl);
//     mlx_loop(mlx);
//     return (0);
// }
