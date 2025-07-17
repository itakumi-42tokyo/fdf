/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:22 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/17 07:31:50 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>


void	


// py = m * (i + 1) + y0;
// d0 = py - y;
// d1 = (y + 1) - py;
// p = m * (i + 1) + y0 - y - y + 1 - m * (i + 1) + y0;
// p = 2 * dy / dx * (i + 1) + 2 * y0  - 2 * y - 1;
// p = 2 *dy * (i + 1) + 2 * y0 * dx - 2 * y *dx - dx;
// p = 2*dy*i + 2*dy + 2*y0*dx - 2*y*dx - dx;
// p = 2*dy*i - 2*dx*y;
// p_next = 2*dy*(i+1) - 2*dx*(y_next);
// p_step = p_next - p;
// p_step = 2*dy*(i+1) - 2*dx*(y_next) - (2*dy*i - 2*dx*y); 
// p_step = 2*dy -2*dx*(y_next -y);
void	bla(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	int		dx;
	int		dy;
	int		dir;
	int		y;
	int		i;
	int		p;
	
	dx = x1 - x0;
	dy = y1 - y0;;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	if (dx != 0)
	{
		y = y0;
		i = 0;
		// p_initial = 2*dy - dx;
		p = 2*dy - dx;
		while (i <= dx + 1)
		{
			mlx_pixel_put(mlx, win, x0 + i, y, 0xFFFFFF);
			if (p >= 0)
			{
				y += 1;
				p = p + 2*dy - 2*dx*(1);		
			}
			else
				p = p + 2*dy - 2*dx*(0);
			i++;
		}
	}
}

void	bla(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	
}

int	expose_hook(void *param)
{
	void	**p = (void **)param;
	void	*mlx = p[0];
	void	*win = p[1];
	bla(0, 0, 900, 900, mlx, win);
}

int	main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 900, 900, "win0");
	void	*param[3] = {mlx, win, NULL};
	mlx_expose_hook(win, expose_hook, param);
	mlx_loop(mlx);
	return (0);
}
