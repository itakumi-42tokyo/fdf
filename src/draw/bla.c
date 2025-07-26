/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:22 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 21:03:47 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <stdlib.h>
#include <math.h>
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
		while (i <= dx)
		{
			mlx_pixel_put(mlx, win, x0 + i, y, 0xFFFFFF);
			if (p >= 0)
			{
				y += dir;
				p = p + 2*dy - 2*dx;
			}
			else
				p = p + 2*dy;
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
		while (i <= dy)
		{
			mlx_pixel_put(mlx, win, x, y0 + i, 0xFFFFFF);
			if (p >= 0)
			{
				x += dir;
				p = p + 2*dx - 2*dy;
			}
			else
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

static int	transform_coord(double value, double scale, int offset)
{
    return (int)round(value * scale + offset);
}

int	hook_bla(void *param)
{
    t_control	**ctrl = (t_control **)param;
    int			i;
    int			j;
    int			x0;
    int			y0;
    int			x1;
    int			y1;

    i = 0;
    while (i < (*ctrl)->map_height)
    {
        j = 0;
        while (j < (*ctrl)->map_width)
        {
            x0 = transform_coord((*ctrl)->persp_map[i][j].persp_x,
                                 (*ctrl)->scale, (*ctrl)->offset_x);
            y0 = transform_coord((*ctrl)->persp_map[i][j].persp_y,
                                 (*ctrl)->scale, (*ctrl)->offset_y);
            if (j + 1 < (*ctrl)->map_width)
            {

                x1 = transform_coord((*ctrl)->persp_map[i][j + 1].persp_x,
                                     (*ctrl)->scale, (*ctrl)->offset_x);
                y1 = transform_coord((*ctrl)->persp_map[i][j + 1].persp_y,
                                     (*ctrl)->scale, (*ctrl)->offset_y);
                printf("--- Step 3: Draw Coords ---\n"); // ループの最初だけ確認するため、if (i == 0 && j == 0) で囲んでも良い
                printf("Drawing line from (%d, %d) to (%d, %d)\n", x0, y0, x1, y1);
                bla(x0, y0, x1, y1, (*ctrl)->mlx, (*ctrl)->win);
                // mlx_pixel_put((*ctrl)->mlx, (*ctrl)->win, x0, y0, 0xFF0000);
            }
            if (i + 1 < (*ctrl)->map_height)
            {
                x1 = transform_coord((*ctrl)->persp_map[i + 1][j].persp_x,
                                     (*ctrl)->scale, (*ctrl)->offset_x);
                y1 = transform_coord((*ctrl)->persp_map[i + 1][j].persp_y,
                                     (*ctrl)->scale, (*ctrl)->offset_y);
                printf("--- Step 3: Draw Coords ---\n"); // ループの最初だけ確認するため、if (i == 0 && j == 0) で囲んでも良い
                printf("Drawing line from (%d, %d) to (%d, %d)\n", x0, y0, x1, y1);
                bla(x0, y0, x1, y1, (*ctrl)->mlx, (*ctrl)->win);
                // mlx_pixel_put((*ctrl)->mlx, (*ctrl)->win, x0, y0, 0xFF0000);
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
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 900, 900, "win0");
//     t_control ctrl = {mlx, win, NULL};
//     mlx_expose_hook(win, hook_bla, &ctrl);
//     mlx_loop(mlx);
//     return (0);
// }
