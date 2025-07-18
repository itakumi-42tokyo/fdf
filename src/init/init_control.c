/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init0_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:02:53 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 18:41:36 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "struct.h"
#include "macro.h"

void	init0_control(t_control *control)
{
	control->mlx = NULL;
	control->win = NULL;
	control->img = NULL;
	control->size_x = 0;
	control->size_y = 0;
	control->title = NULL;
	control->bits_per_pixel = 0;
	control->size_line = 0;
	control->endian = 0;
	control->data_addr = NULL;
	control->map = NULL;
	control->map_width = 0;
	control->map_height = 0;
}

void	init_control(t_control *control)
{
	if (control == NULL)
		return ;
	init0_control(control);
	control->size_x = DEFAULT_WIN_SIZE_X;
	control->size_y = DEFAULT_WIN_SIZE_Y;
	control->title = DEFAULT_TITLE;
	control->map_width = 0;
	control->map_height = 0;
}
