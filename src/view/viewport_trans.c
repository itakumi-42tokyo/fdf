/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 06:43:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 06:49:45 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "struct.h"
#include "macro.h"

void apply_viewport_transform(t_control *ctrl)
{
    int i, j;
    double center_x, center_y;

    if (ctrl == NULL)
        return;

    center_x = ctrl->win_size_x / 2.0;
    center_y = ctrl->win_size_y / 2.0;

    i = 0;
    while (i < ctrl->map_height)
    {
        j = 0;
        while (j < ctrl->map_width)
        {
            if (PROJ == ISO)
            {
                ctrl->iso_map[i][j].iso_x += center_x;
                ctrl->iso_map[i][j].iso_y += center_y;
            }
            else
            {
                ctrl->persp_map[i][j].persp_x += center_x;
                ctrl->persp_map[i][j].persp_y += center_y;
            }
            j++;
        }
        i++;
    }
}
