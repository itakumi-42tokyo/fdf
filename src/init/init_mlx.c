/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 16:52:23 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro.h"
#include "mlx.h"
#include "struct.h"
#include "utils.h"
#include <stdlib.h>

void	init_mlx(t_control *ctrl)
{
	ctrl->mlx = mlx_init();
	if (ctrl->mlx == NULL)
		(errmsg_exit(FAILED_MLX_INIT));
	mlx_get_screen_size(ctrl->mlx, &(ctrl->win_size_x), &(ctrl->win_size_y));
	if (ctrl->win_size_x <= 0 || ctrl->win_size_y <= 0)
	{
		ctrl->win_size_x = DEFAULT_WIN_SIZE_X;
		ctrl->win_size_y = DEFAULT_WIN_SIZE_Y;
	}
	ctrl->win = mlx_new_window(ctrl->mlx, ctrl->win_size_x, ctrl->win_size_y,
			ctrl->title);
	if (ctrl->win == NULL)
	{
		mlx_destroy_display(ctrl->mlx);
		free(ctrl->mlx);
		errmsg_exit(FAILED_MLX_WIN);
	}
	ctrl->img = mlx_new_image(ctrl->mlx, ctrl->win_size_x, ctrl->win_size_y);
	if (ctrl->img == NULL)
	{
		mlx_destroy_window(ctrl->mlx, ctrl->win);
		mlx_destroy_display(ctrl->mlx);
		free(ctrl->mlx);
		errmsg_exit(FAILED_MLX_IMG);
	}
	ctrl->data_addr = mlx_get_data_addr(ctrl->img, &(ctrl->bits_per_pixel),
			&(ctrl->size_line), &(ctrl->endian));
	if (ctrl->data_addr == NULL)
	{
		mlx_destroy_window(ctrl->mlx, ctrl->win);
		mlx_destroy_image(ctrl->mlx, ctrl->img);
		mlx_destroy_display(ctrl->mlx);
		free(ctrl->mlx);
		errmsg_exit(FAILED_MLX_DATA_ADDR);
	}
}
