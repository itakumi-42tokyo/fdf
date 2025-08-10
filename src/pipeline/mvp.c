/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 07:29:03 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/08 11:32:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "struct.h"
#include "utils.h"
#include "macro.h"

// mvp行列をマップ座標に掛け合わせる。
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
			vec_pre.com.x= ctrl->map[i][j].x;
			vec_pre.com.y= ctrl->map[i][j].y;
			vec_pre.com.z = ctrl->map[i][j].z;
			vec_pre.com.w = 1;
			vec_new = mul_mat4_vec4(matrix, vec_pre);
			if (PROJ == ISO)
			{
				ctrl->iso_map[i][j].iso_x = vec_new.com.x;
				ctrl->iso_map[i][j].iso_y = vec_new.com.y;
				ctrl->iso_map[i][j].color = ctrl->map[i][j].color;
			}
			else
			{
				ctrl->persp_map[i][j].persp_x = vec_new.com.x;
				ctrl->persp_map[i][j].persp_y = vec_new.com.y;
				ctrl->persp_map[i][j].color = ctrl->map[i][j].color;
			}
			j++;
		}
		i++;
	}
}
