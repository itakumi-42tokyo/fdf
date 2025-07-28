/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:28:50 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/28 17:01:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <stdbool.h>
#include "struct.h"
#include "exit.h"

int	mouse_press(int button, int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	(*ctrl)->mouse.is_pressed = true;
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	(*ctrl)->mouse.is_pressed = false;
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if ((*ctrl)->mouse.is_pressed == true)
	{

	}
	printf("x: %d; y: %d\n", x, y);
	return (0);
}

int	close_window(void *param)
{
	t_control **ctrl;

	ctrl = (t_control **)param;
	free_exit(ctrl);
	return (-1);
}
