/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:28:50 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/01 23:09:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <mlx.h>
#include <stdbool.h>
#include "struct.h"
#include "exit.h"
#include "view.h"
#include "draw.h"
#include "rotate.h"

// increase scale
int	mouse_scroll_up(int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	(*ctrl)->zoom *= 1.1;
	render(param);
	puts("role_up");
	return (0);
}

// decrease scale
int		mouse_scroll_down(int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	(*ctrl)->zoom /= 1.1;
	render(param);
	puts("role_down");
	return (0);
}

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
		puts("left_mouse_button");
	}
	else if (button == 2)
	{
		puts("middle_mouse_button");
	}
	else if (button == 3)
	{
		puts("right_mouse_button");
	}
	else if (button == 4)
	{
		mouse_scroll_up(x, y, param);
	}
	else if (button == 5)
	{
		mouse_scroll_down(x, y, param);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	(*ctrl)->mouse.is_pressed = false;
	puts("release_button");
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_control	**ctrl;
	double		delta_x;
	double		delta_y;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if ((*ctrl)->mouse.is_pressed == true)
	{
		// rotate
		// 差分だけコントロールするようにすればいいかな
		delta_x = x - (*ctrl)->mouse.x;
		delta_y = y - (*ctrl)->mouse.y;
		(*ctrl)->total_angle_x += delta_x * 0.5;
		(*ctrl)->total_angle_y += delta_y * 0.5;
		render(param);
		// (*ctrl)->angle_x += (y - prev_y) * 0.005;// unused
		// (*ctrl)->angle_y += (x - prev_x) * 0.005;// unused
	}
	(*ctrl)->mouse.x = x;
	(*ctrl)->mouse.y = y;
	return (0);
}

int	close_window(void *param)
{
	t_control **ctrl;

	ctrl = (t_control **)param;
	free_exit(ctrl);
	return (-1);
}
