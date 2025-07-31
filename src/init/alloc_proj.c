/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_proj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:00:29 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/31 19:30:26 by itakumi          ###   ########.fr       */
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

	iso_map = ft_calloc(sizeof(t_isometric *) * height + 1, 1);
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
	return (iso_map);
}

t_perspective	**calloc_persp(int height, int width)
{
	t_perspective	**persp_map;
	int				i;

	persp_map = ft_calloc(sizeof(t_perspective *) * height + 1, 1);
	if (persp_map == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		persp_map[i] = ft_calloc(sizeof(t_perspective) * width, 1);
		if (persp_map[i] == NULL)
			return (free_2d((void **)persp_map), NULL);
		i++;
	}
	return (persp_map);
}

int	alloc_proj(t_control *ctrl, int proj_flag)
{
	if (ctrl == NULL)
		return (-1);
	if (proj_flag == ISO)
	{
		ctrl->iso_map = calloc_iso();
		if (ctrl->iso_map == NULL)
			return (-1);
	}
	else if (proj_flag == PERSP)
	{
		ctrl->persp_map = calloc_persp();
		if (ctrl->persp_map == NULL)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
