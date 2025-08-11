/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 07:29:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 01:26:45 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro.h"
#include "struct.h"
#include "utils.h"
#include <stddef.h>

static void	init_vector(t_vector4 *vec_pre, double x, double y, double z)
{
	(*vec_pre).com.x = x;
	(*vec_pre).com.y = y;
	(*vec_pre).com.z = z;
	(*vec_pre).com.w = 1;
}

static void	substitute_screen(t_vector4 vec_new, t_control *ctrl, int i, int j)
{
	if (PROJ == ISO)
	{
		ctrl->iso_map[i][j].iso_x = vec_new.com.x;
		ctrl->iso_map[i][j].iso_y = vec_new.com.y;
		ctrl->iso_map[i][j].color = ctrl->map[i][j].color;
	}
	else if (PROJ == PERSP)
	{
		ctrl->persp_map[i][j].persp_x = vec_new.com.x;
		ctrl->persp_map[i][j].persp_y = vec_new.com.y;
		ctrl->persp_map[i][j].color = ctrl->map[i][j].color;
	}
	else
	{
		ctrl->cur_map[i][j].x = vec_new.com.x;
		ctrl->cur_map[i][j].y = vec_new.com.y;
		ctrl->cur_map[i][j].z = vec_new.com.z;
		ctrl->cur_map[i][j].color = ctrl->map[i][j].color;
	}
}

void	apply_mvp(t_control *ctrl, double matrix[4][4])
{
	t_vector4	vec_pre;
	t_vector4	vec_new;
	int			i;
	int			j;

	if (ctrl == NULL)
		return ;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			init_vector(&vec_pre,
				ctrl->map[i][j].x, ctrl->map[i][j].y, ctrl->map[i][j].z);
			vec_new = mul_mat4_vec4(matrix, vec_pre);
			substitute_screen(vec_new, ctrl, i, j);
			j++;
		}
		i++;
	}
}
