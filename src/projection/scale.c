/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:21:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/22 14:39:39 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <math.h>
#include "macro.h"
#include "struct.h"

static max_iso_y(t_control *ctrl)
{
	int	i;
	int	j;
	int	max;

	if (ctrl == NULL)
		return (-1);
	max = INT_MIN;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			if (max < ctrl->iso_map[i][j].iso_y)
				max = ctrl->iso_map[i][j].iso_y;
			j++;
		}
		i++;
	}
	return (max);
}

static int	max_iso_x(t_control *ctrl)
{
	int	i;
	int	j;
	int	max;

	if (ctrl == NULL)
		return (-1);
	max = INT_MIN;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			if (max < ctrl->iso_map[i][j].iso_x)
				max = ctrl->iso_map[i][j].iso_x;
			j++;
		}
		i++;
	}
	return (max);
}

static inline int min_iso_x(t_control *ctrl)
{
	int	i;
	int	j;
	int	min;

	if (ctrl == NULL)
		return (-1);
	min = INT_MAX;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			if (min > (ctrl->iso_map[i][j]).iso_x)
				min = (ctrl->iso_map[i][j]).iso_x;
			j++;
		}
		i++;
	}
	return (min);
}

static inline int min_iso_y(t_control *ctrl)
{
	int	i;
	int	j;
	int	min;

	if (ctrl == NULL)
		return (-1);
	min = INT_MAX;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			if (min > ctrl->iso_map[i][j].iso_x)
				min = ctrl->iso_map[i][j].iso_x;
			j++;
		}
		i++;
	}
	return (min);
}

void	scale(t_control *ctrl)
{
	int		iso_width0_hight1[2];
	double	scale_x0_y1[2];

	ctrl->iso_min_x0_y1[0] = min_iso_x(ctrl);
	ctrl->iso_min_x0_y1[1] = min_iso_y(ctrl);
	iso_width0_hight1[0] = max_iso_x(ctrl) - ctrl->iso_min_x0_y1[0];
	iso_width0_hight1[1] = max_iso_y(ctrl) - ctrl->iso_min_x0_y1[1];
	scale_x0_y1[0] = (ctrl->win_size_x * 0.9) / iso_width0_hight1[0];
	scale_x0_y1[1] = (ctrl->win_size_y * 0.9) / iso_width0_hight1[1];
	ctrl->scale = fmax(scale_x0_y1[0], scale_x0_y1[1]);
}
