/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:02:53 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 05:22:30 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "struct.h"
#include "macro.h"

// 本当に必要であるか

static void	_init0(t_control *control)
{
	control->mlx = NULL;
	control->win = NULL;
	control->img = NULL;
	control->win_size_x = 0;
	control->win_size_y = 0;
	control->title = NULL;
	control->bits_per_pixel = 0;
	control->size_line = 0;
	control->endian = 0;
	control->data_addr = NULL;
	control->map = NULL;
	control->cur_map = NULL;
	control->iso_map = NULL;
	ft_bzero(control->iso_min_x0_y1, 2);
	control->persp_map = NULL;
}

void	init0_control(t_control *control)
{
	_init0(control);
	control->map_width = 0;
	control->map_height = 0;
	control->offset_x = 0;
	control->offset_y = 0;
	control->scale = 0;
	control->mag_rate = 0;
	control->mouse.x = 0;
	control->mouse.y = 0;
	control->mouse.is_pressed = false;
	control->total_angle_x = 0;
	control->total_angle_y = 0;
	control->zoom = 0;
	control->camera.pos_x = 0;
	control->camera.pos_y = 0;
	control->camera.pos_z = 0;
	control->total_trans_x = 0;
	control->total_trans_y = 0;
	control->key_r_pressed = false;
}

void	init_control(t_control *control)
{
	if (control == NULL)
		return ;
	control->title = DEFAULT_TITLE;
	control->offset_x = DEFAULT_WIN_SIZE_X / 2;
	control->offset_y = DEFAULT_WIN_SIZE_Y / 2;
	control->scale = 30;
	control->mag_rate = 45;
	control->zoom = 0.9;
	control->camera.fov = M_PI / 4;
	control->camera.aspect
		= (double)((double)control->win_size_x / (double)control->win_size_y);
	control->camera.near = 0.1;
	control->camera.far = 1000.0;
	control->camera.focus = 1.0 / tan(control->camera.fov / 2.0);
}
