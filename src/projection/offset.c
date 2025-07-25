/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-25 20:52:59 by tigarashi         #+#    #+#             */
/*   Updated: 2025-07-25 20:52:59 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	offset(t_control *ctrl)
{
	ctrl->offset_x = (int)round((ctrl->win_size_x - ((ctrl->iso_max_x0_y1)[0] - ctrl->iso_min_x0_y1[0]) * ctrl->scale) / 2.0);
	ctrl->offset_y = (int)round((ctrl->win_size_y - ((ctrl->iso_max_x0_y1)[1] - ctrl->iso_min_x0_y1[1]) * ctrl->scale) / 2.0);
}