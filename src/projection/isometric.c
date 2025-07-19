/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:58:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/19 17:24:54 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "struct.h"
#include "projction.h"

void	iso_proj(t_control *ctrl)
{
	t_point	**map;
	int 		i;
	int 		j;
	int			x_new;
	int			y_new;
	int			z_new;

	if (ctrl == NULL)
		return;
	map = ctrl->map;
	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			x_new = (map[i][j]).x * cos(deg_to_rad(45)) + (map[i][j]).z * sin(deg_to_rad(45));
			y_new = (map[i][j]).y;
			z_new = -(map[i][j]).x * cos(deg_to_rad(45)) + (map[i][j]).z * cos(deg_to_rad(45));

			x_new = x_new;
			y_new = (map[i][j]).y * cos(deg_to_rad(-35.26)) - z_new * sin(deg_to_rad(-35.26));
			ctrl->iso_map[i][j].iso_x = x_new;
			ctrl->iso_map[i][j].iso_y = y_new;
			j++;
		}
		i++;
	}
