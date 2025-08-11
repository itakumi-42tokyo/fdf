/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:28:50 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 19:38:54 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <stdbool.h>
#include "draw.h"
#include "exit.h"
#include "macro.h"
#include "rotate.h"
#include "struct.h"
#include "view.h"

// increase scale
int	mouse_scroll_up(int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if ((*ctrl)->zoom < ZOOM_MAX)
		(*ctrl)->zoom *= 1.1;
	render(param);
	write(1, "scroll up!\n", ft_strlen("scroll up!\n"));
	return (0);
}

// decrease scale
int	mouse_scroll_down(int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if ((*ctrl)->zoom > ZOOM_MIN)
		(*ctrl)->zoom /= 1.1;
	render(param);
	write(1, "scroll down!\n", ft_strlen("scroll down!\n"));
	return (0);
}

// 回転と拡大縮小を同時にしたら拡大縮小が優先された
int	mouse_press(int button, int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (button == 1)
	{
		(*ctrl)->mouse.is_pressed = true;
		(*ctrl)->mouse.x = x;
		(*ctrl)->mouse.y = y;
		write(1, MOUSE_LEFT_BUTTON, ft_strlen(MOUSE_LEFT_BUTTON));
	}
	else if (button == 2)
		write(1, MOUSE_MIDDLE_BUTTON, ft_strlen(MOUSE_MIDDLE_BUTTON));
	else if (button == 3)
		write(1, MOUSE_RIGHT_BUTTON, ft_strlen(MOUSE_RIGHT_BUTTON));
	else if (button == 4)
		mouse_scroll_up(x, y, param);
	else if (button == 5)
		mouse_scroll_down(x, y, param);
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	(*ctrl)->mouse.is_pressed = false;
	write(1, MOUSE_RELEASE, ft_strlen(MOUSE_RELEASE));
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_control	**ctrl;
	float		delta_x;
	float		delta_y;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if ((*ctrl)->mouse.is_pressed == true)
	{
		delta_x = x - (*ctrl)->mouse.x;
		delta_y = y - (*ctrl)->mouse.y;
		if ((*ctrl)->total_angle_x < FLT_MAX)
			(*ctrl)->total_angle_x += delta_x * 0.5;
		if ((*ctrl)->total_angle_y < FLT_MAX)
			(*ctrl)->total_angle_y += delta_y * 0.5;
		render(param);
	}
	(*ctrl)->mouse.x = x;
	(*ctrl)->mouse.y = y;
	return (0);
}
