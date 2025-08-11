/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:22 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 18:42:15 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include "macro.h"
#include "mlx.h"
#include "struct.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void	set_pixel(t_control *ctrl, int x, int y, int color)
{
	int		bytes;
	char	*dst;

	bytes = ctrl->bits_per_pixel / 8;
	if (x < 0 || x >= ctrl->win_size_x || y < 0 || y >= ctrl->win_size_y)
		return ;
	dst = ctrl->data_addr + y * ctrl->size_line + x * bytes;
	*(unsigned int *)dst = color;
}

void	bla_h(int xy0[2], int xy1[2], t_control *ctrl)
{
	int	dx;
	int	dy;
	int	dir;
	int	y;
	int	i;
	int	p;

	if (xy0[0] > xy1[0])
	{
		swap(&xy0[0], &xy1[0]);
		swap(&xy0[1], &xy1[1]);
	}
	dx = xy1[0] - xy0[0];
	dy = xy1[1] - xy0[1];
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	if (dx != 0)
	{
		y = xy0[1];
		i = 0;
		p = 2 * dy - dx;
		while (i <= dx)
		{
			set_pixel(ctrl, xy0[0] + i, y, 0xFFFFFF);
			if (p >= 0)
			{
				y += dir;
				p = p + 2 * dy - 2 * dx;
			}
			else
				p = p + 2 * dy;
			i++;
		}
	}
}

void	bla_v(int xy0[2], int xy1[2], t_control *ctrl)
{
	int	dx;
	int	dy;
	int	dir;
	int	x;
	int	i;
	int	p;

	if (xy0[1] > xy1[1])
	{
		swap(&xy0[0], &xy1[0]);
		swap(&xy0[1], &xy1[1]);
	}
	dx = xy1[0] - xy0[0];
	dy = xy1[1] - xy0[1];
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	if (dy != 0)
	{
		x = xy0[0];
		i = 0;
		p = 2 * dx - dy;
		while (i <= dy)
		{
			set_pixel(ctrl, x, xy0[1] + i, 0xFFFFFF);
			if (p >= 0)
			{
				x += dir;
				p = p + 2 * dx - 2 * dy;
			}
			else
				p = p + 2 * dx;
			i++;
		}
	}
}

void	bla(int xy0[2], int xy1[2], t_control *ctrl)
{
	int	dx;
	int	dy;

	dx = xy1[0] - xy0[0];
	dy = xy1[1] - xy0[1];
	if (my_abs(dx) > my_abs(dy))
		bla_h(xy0, xy1, ctrl);
	else
		bla_v(xy0, xy1, ctrl);
}

static int	transform_coord(double value, double scale, int offset)
{
	return ((int)round(value * scale + offset));
}

static int	drawline_persp(t_control *ctrl)
{
	int			i;
	int			j;
	int			xy0[2];
	int			xy1[2];

	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			xy0[0] = transform_coord(ctrl->persp_map[i][j].persp_x,
					ctrl->scale, ctrl->offset_x);
			xy0[1] = transform_coord(ctrl->persp_map[i][j].persp_y,
					ctrl->scale, ctrl->offset_y);
			if (j + 1 < ctrl->map_width)
			{
				xy1[0] = transform_coord(ctrl->persp_map[i][j + 1].persp_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->persp_map[i][j + 1].persp_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl);
			}
			if (i + 1 < ctrl->map_height)
			{
				xy1[0] = transform_coord(ctrl->persp_map[i + 1][j].persp_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->persp_map[i + 1][j].persp_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	drawline_iso(t_control *ctrl)
{
	int			i;
	int			j;
	int			xy0[2];
	int			xy1[2];

	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			xy0[0] = transform_coord(ctrl->iso_map[i][j].iso_x, ctrl->scale,
					ctrl->offset_x);
			xy0[1] = transform_coord(ctrl->iso_map[i][j].iso_y, ctrl->scale,
					ctrl->offset_y);
			if (j + 1 < ctrl->map_width)
			{
				xy1[0] = transform_coord(ctrl->iso_map[i][j + 1].iso_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->iso_map[i][j + 1].iso_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl);
			}
			if (i + 1 < ctrl->map_height)
			{
				xy1[0] = transform_coord(ctrl->iso_map[i + 1][j].iso_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->iso_map[i + 1][j].iso_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	hook_bla(void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (PROJ == ISO)
		drawline_iso(*ctrl);
	else if (PROJ == PERSP)
		drawline_persp(*ctrl);
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
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 900, 900, "win0");
//     t_control ctrl = {mlx, win, NULL};
//     mlx_expose_hook(win, hook_bla, &ctrl);
//     mlx_loop(mlx);
//     return (0);
// }
