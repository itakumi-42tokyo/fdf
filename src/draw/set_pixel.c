/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:05:10 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 02:05:26 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "macro.h"
#include "struct.h"

void	set_pixel(t_control *ctrl, int x, int y, int color)
{
	int		bytes;
	char	*dst;

	bytes = ctrl->bits_per_pixel / 8;
	if (x < 0 || x >= ctrl->win_size_x || y < 0 || y >= ctrl->win_size_y)
		return ;
	dst = ctrl->data_addr + y * ctrl->size_line + x * bytes;
	*(unsigned int *)dst = color;
}
