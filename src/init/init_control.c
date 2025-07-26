/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:02:53 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 20:54:47 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "struct.h"
#include "macro.h"

void	init0_control(t_control *control)
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
	control->iso_map = NULL;
	ft_bzero(control->iso_min_x0_y1, 2);
	control->persp_map = NULL;
	control->map_width = 0;
	control->map_height = 0;
	control->offset_x = 0;
	control->offset_y = 0;
	control->scale = 0;
	control->mag_rate = 0;
}

void	init_control(t_control *control)
{
	if (control == NULL)
		return ;
	init0_control(control);
	control->win_size_x = DEFAULT_WIN_SIZE_X;
	control->win_size_y = DEFAULT_WIN_SIZE_Y;
	control->title = DEFAULT_TITLE;
	control->map_width = 0;
	control->map_height = 0;
	control->offset_x = DEFAULT_WIN_SIZE_X / 2;
	control->offset_y = DEFAULT_WIN_SIZE_Y / 2;
	control->scale = 30;
	control->mag_rate = 45;
}
