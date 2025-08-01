/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_proj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:00:29 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/01 22:05:09 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "struct.h"
#include "macro.h"
#include "utils.h"

t_isometric	**calloc_iso(int height, int width)
{
	t_isometric		**iso_map;
	int				i;

	iso_map = ft_calloc(sizeof(t_isometric *) * (height + 1), 1);
	if (iso_map == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		iso_map[i] = ft_calloc(sizeof(t_isometric) * width, 1);
		if (iso_map[i] == NULL)
			return (free_2d((void **)iso_map), NULL);
		i++;
	}
	iso_map[i] == NULL;
	return (iso_map);
}

t_perspective	**calloc_persp(int height, int width)
{
	t_perspective	**persp_map;
	int				i;

	persp_map = ft_calloc(sizeof(t_perspective *) * (height + 1), 1);
	if (persp_map == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		persp_map[i] = ft_calloc(sizeof(t_perspective) * width, 1);
		if (persp_map[i] == NULL)
			return (free_2d((void **)persp_map), NULL);// FIXME
		i++;
	}
	persp_map[i] = NULL;
	return (persp_map);
}

int	alloc_proj(t_control *ctrl)
{
	if (ctrl == NULL)
		return (-1);
	if (PROJ == ISO)
	{
		ctrl->iso_map = calloc_iso(ctrl->map_height, ctrl->map_width);
		if (ctrl->iso_map == NULL)
			return (-1);
	}
	else if (PROJ == PERSP)
	{
		ctrl->persp_map = calloc_persp(ctrl->map_height, ctrl->map_width);
		if (ctrl->persp_map == NULL)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
