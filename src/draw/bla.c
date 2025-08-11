/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:22 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 02:26:26 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "macro.h"
#include "mlx.h"
#include "struct.h"
#include "utils.h"
#include "draw.h"

static void	init_delta_h(int dx0_dy1[2], int xy0[2], int xy1[2], int *dir)
{
	*dir = 1;
	if (xy0[0] > xy1[0])
	{
		swap(&xy0[0], &xy1[0]);
		swap(&xy0[1], &xy1[1]);
	}
	dx0_dy1[0] = xy1[0] - xy0[0];
	dx0_dy1[1] = xy1[1] - xy0[1];
}

static void	init_delta_v(int dx0_dy1[2], int xy0[2], int xy1[2], int *dir)
{
	*dir = 1;
	if (xy0[1] > xy1[1])
	{
		swap(&xy0[0], &xy1[0]);
		swap(&xy0[1], &xy1[1]);
	}
	dx0_dy1[0] = xy1[0] - xy0[0];
	dx0_dy1[1] = xy1[1] - xy0[1];
}

void	bla_h(int xy0[2], int xy1[2], int color, t_control *ctrl)
{
	int	dx0_dy1[2];
	int	dir;
	int	y;
	int	i;
	int	p;

	init_delta_h(dx0_dy1, xy0, xy1, &dir);
	if (dx0_dy1[1] < 0)
		dir = -1;
	dx0_dy1[1] *= dir;
	if (dx0_dy1[0] == 0)
		return ;
	y = xy0[1];
	i = 0;
	p = 2 * dx0_dy1[1] - dx0_dy1[0];
	while (i <= dx0_dy1[0])
	{
		(set_pixel(ctrl, xy0[0] + i, y, color), i++);
		if (p >= 0)
		{
			y += dir;
			p += -2 * dx0_dy1[0];
		}
		p += 2 * dx0_dy1[1];
	}
}

void	bla_v(int xy0[2], int xy1[2], int color, t_control *ctrl)
{
	int	dx0_dy1[2];
	int	dir;
	int	x;
	int	i;
	int	p;

	init_delta_v(dx0_dy1, xy0, xy1, &dir);
	if (dx0_dy1[0] < 0)
		dir = -1;
	dx0_dy1[0] *= dir;
	if (dx0_dy1[1] == 0)
		return ;
	x = xy0[0];
	i = 0;
	p = 2 * dx0_dy1[0] - dx0_dy1[1];
	while (i <= dx0_dy1[1])
	{
		(set_pixel(ctrl, x, xy0[1] + i, color), i++);
		if (p >= 0)
		{
			x += dir;
			p += -2 * dx0_dy1[1];
		}
		p += 2 * dx0_dy1[0];
	}
}

// 	int	p;

// 	if (xy0[1] > xy1[1])
// 	{
// 		swap(&xy0[0], &xy1[0]);
// 		swap(&xy0[1], &xy1[1]);
// 	}
// 	dx = xy1[0] - xy0[0];
// 	dy = xy1[1] - xy0[1];
// 	if (dx < 0)
// 		dir = -1;
// 	else
// 		dir = 1;
// 	dx *= dir;
// 	if (dy != 0)
// 	{
// 		x = xy0[0];
// 		i = 0;
// 		p = 2 * dx - dy;
// 		while (i <= dy)
// 		{
// 			set_pixel(ctrl, x, xy0[1] + i, 0xFFFFFF);
// 			if (p >= 0)
// 			{
// 				x += dir;
// 				p = p + 2 * dx - 2 * dy;
// 			}
// 			else
// 				p = p + 2 * dx;
// 			i++;
// 		}
// 	}
// }

void	bla(int xy0[2], int xy1[2], int color, t_control *ctrl)
{
	int	dx;
	int	dy;

	dx = xy1[0] - xy0[0];
	dy = xy1[1] - xy0[1];
	if (my_abs(dx) > my_abs(dy))
		bla_h(xy0, xy1, color, ctrl);
	else
		bla_v(xy0, xy1, color, ctrl);
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
