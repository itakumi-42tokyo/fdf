/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 01:34:34 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 02:23:48 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "draw.h"
#include "macro.h"
#include "struct.h"

static int	transform_coord(double value, double scale, int offset)
{
	return ((int)round(value * scale + offset));
}

static int	drawline_persp(t_control *ctrl)
{
	int			i;
	int			j;
	int			xy0[2];
	int			xy1[2];

	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			xy0[0] = transform_coord(ctrl->persp_map[i][j].persp_x,
					ctrl->scale, ctrl->offset_x);
			xy0[1] = transform_coord(ctrl->persp_map[i][j].persp_y,
					ctrl->scale, ctrl->offset_y);
			if (j + 1 < ctrl->map_width)
			{
				xy1[0] = transform_coord(ctrl->persp_map[i][j + 1].persp_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->persp_map[i][j + 1].persp_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl->persp_map[i][j].color, ctrl);
			}
			if (i + 1 < ctrl->map_height)
			{
				xy1[0] = transform_coord(ctrl->persp_map[i + 1][j].persp_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->persp_map[i + 1][j].persp_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl->persp_map[i][j].color, ctrl);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	drawline_iso(t_control *ctrl)
{
	int			i;
	int			j;
	int			xy0[2];
	int			xy1[2];

	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			xy0[0] = transform_coord(ctrl->iso_map[i][j].iso_x, ctrl->scale,
					ctrl->offset_x);
			xy0[1] = transform_coord(ctrl->iso_map[i][j].iso_y, ctrl->scale,
					ctrl->offset_y);
			if (j + 1 < ctrl->map_width)
			{
				xy1[0] = transform_coord(ctrl->iso_map[i][j + 1].iso_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->iso_map[i][j + 1].iso_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl->iso_map[i][j].color, ctrl);
			}
			if (i + 1 < ctrl->map_height)
			{
				xy1[0] = transform_coord(ctrl->iso_map[i + 1][j].iso_x,
						ctrl->scale, ctrl->offset_x);
				xy1[1] = transform_coord(ctrl->iso_map[i + 1][j].iso_y,
						ctrl->scale, ctrl->offset_y);
				bla(xy0, xy1, ctrl->iso_map[i][j].color, ctrl);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	hook_bla(void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (PROJ == ISO)
		drawline_iso(*ctrl);
	else if (PROJ == PERSP)
		drawline_persp(*ctrl);
	return (0);
}
