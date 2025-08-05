/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 04:14:11 by tigarashi         #+#    #+#             */
/*   Updated: 2025/08/01 21:55:26 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <linux/input-event-codes.h>
#include <stdlib.h>
#include "mlx.h"
#include "struct.h"
#include "macro.h"
#include "exit.h"


// macOS 対応は要検討
int key_press(int keycode, void	*param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (keycode == ESC_LINUX)
		free_exit(ctrl);
	else if (keycode == R_LINUX)
	{
		// Reset the view
		(*ctrl)->total_angle_x = 0;
		(*ctrl)->total_angle_y = 0;
		(*ctrl)->scale = 1.0;
		(*ctrl)->offset_x = 0;
		(*ctrl)->offset_y = 0;
		printf("View reset to default.\n");
	}
	else if (keycode == X_LINUX)
	{
		printf("X key pressed, performing action...\n");
	}
	else if (keycode == ESC_MACOS)
		free_exit(ctrl);
	else
	{
		printf("Unhandled keycode: %d\n", keycode);
	}
	printf("keycode: %d\n", keycode);
	return (-1);
}

// int	main(void)
// {
// 	void	*mlx = mlx_init();
// 	void	*win = mlx_new_window(mlx, 900, 900, "window01");
// 	void	*param[3] = {mlx, win, NULL};
// 	mlx_key_hook(win, key_hook, param);
// 	mlx_loop(mlx);
// 	return (0);
// }
