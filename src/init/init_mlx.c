/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/22 14:30:44 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "macro.h"
#include "struct.h"
#include "utils.h"

void	init_mlx(t_control *ctrl)
{
	ctrl->mlx = mlx_init();
	if (ctrl->mlx == NULL)
		(errmsg_exit(FAILED_MLX_INIT));
	ctrl->win = mlx_new_window(ctrl->mlx, ctrl->win_size_x, ctrl->win_size_y, ctrl->title);
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
	ctrl->data_addr = mlx_get_data_addr(ctrl->img, &(ctrl->bits_per_pixel), &(ctrl->size_line), &(ctrl->endian));
	if (ctrl->data_addr == NULL)
	{
		mlx_destroy_window(ctrl->mlx, ctrl->win);
		mlx_destroy_image(ctrl->mlx, ctrl->img);
		mlx_destroy_display(ctrl->mlx);
		free(ctrl->mlx);
		errmsg_exit(FAILED_MLX_DATA_ADDR);
	}
}
