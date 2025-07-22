/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:58:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/22 16:59:56 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "projection.h"
#include "utils.h"

int	iso_proj(t_control *ctrl)
{
	t_point	**map;
	int 		i;
	int 		j;
	int			x_new;
	int			y_new;
	int			z_new;

	if (ctrl == NULL)
		return (-1);
	ctrl->iso_map = malloc(sizeof(t_control *) * (ctrl->map_height + 1));
	if (ctrl->iso_map == NULL)
		return (-1);
	map = ctrl->map;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		ctrl->iso_map[i] = malloc(sizeof(t_control) * ctrl->map_width);
		if (ctrl->iso_map[i] == NULL)
			return (free_2d((void **)ctrl->iso_map), -1);
		while (j < ctrl->map_width)
		{
			x_new = (map[i][j]).x * cos(deg_to_rad(45)) + (map[i][j]).z * sin(deg_to_rad(45));
			y_new = (map[i][j]).y;
			z_new = -1 * (map[i][j]).x * sin(deg_to_rad(45)) + (map[i][j]).z * cos(deg_to_rad(45));

			x_new = x_new ;
			y_new = y_new * cos(deg_to_rad(-35.26)) - z_new * sin(deg_to_rad(-35.26));
			ctrl->iso_map[i][j].iso_x = x_new;
			ctrl->iso_map[i][j].iso_y = y_new;
			j++;
		}
		i++;
	}
	ctrl->iso_map[i] = NULL;
	return (0);
}
