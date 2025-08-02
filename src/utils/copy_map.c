/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 07:37:28 by tigarashi         #+#    #+#             */
/*   Updated: 2025-08-02 07:37:28 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include "struct.h"

// 必要最小限の引数権限しか持たせないようにしよう。
void	copy_map(t_control *ctrl)
{
	int i;
	int j;

	if (ctrl == NULL || ctrl->map == NULL || ctrl->cur_map == NULL)
		return ;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			ctrl->cur_map[i][j].x = ctrl->map[i][j].x;
			ctrl->cur_map[i][j].y = ctrl->map[i][j].y;
			ctrl->cur_map[i][j].z = ctrl->map[i][j].z;
			ctrl->cur_map[i][j].color = ctrl->map[i][j].color;
			j++;
		}
		i++;
	}
}