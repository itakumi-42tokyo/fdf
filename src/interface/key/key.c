/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 04:14:11 by tigarashi         #+#    #+#             */
/*   Updated: 2025/08/11 16:52:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include "draw.h"
#include "exit.h"
#include "macro.h"
#include "mlx.h"
#include "struct.h"
#include <linux/input-event-codes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// macOS 対応は要検討
int	key_press(int keycode, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (keycode == ESC_LINUX)
		free_exit(ctrl);
	else if (keycode == R_LINUX)
	{
		(*ctrl)->total_angle_x = 0;
		(*ctrl)->total_angle_y = 0;
		(*ctrl)->scale = 30;
		(*ctrl)->offset_x = (*ctrl)->win_size_x / 2;
		(*ctrl)->offset_y = (*ctrl)->win_size_y / 2;
		(*ctrl)->total_trans_x = 0;
		(*ctrl)->total_trans_y = 0;
		(*ctrl)->zoom = 0.9;
		(*ctrl)->mag_rate = 45;
		(*ctrl)->key_r_pressed = true;
		render(param);
		printf("View reset to default.\n");
	}
	else if (keycode == X_LINUX)
	{
		printf("X key pressed, performing action...\n");
	}
	else if (keycode == W_LINUX) // 奥行きを移動させることと縮小することは何が違うのだろうか。
	{                            // 投影変換したものを移動させたほうがわかりやすさはある
		(*ctrl)->total_trans_y++;
		printf("trans_y: %d\n", (*ctrl)->total_trans_y);
		render(param);
	}
	else if (keycode == A_LINUX)
	{
		(*ctrl)->total_trans_x--;
		printf("trans_x: %d\n", (*ctrl)->total_trans_x);
		render(param);
	}
	else if (keycode == S_LINUX)
	{
		(*ctrl)->total_trans_y--;
		printf("trans_y: %d\n", (*ctrl)->total_trans_y);
		render(param);
	}
	else if (keycode == D_LINUX)
	{
		(*ctrl)->total_trans_x++;
		printf("trans_x: %d\n", (*ctrl)->total_trans_x);
		render(param);
	}
	else if (keycode == CURSOR_UP_LINUX)
	{
	}
	else if (keycode == CURSOR_DOWN_LINUX)
	{
	}
	else if (keycode == CURSOR_LEFT_LINUX)
	{
	}
	else if (keycode == CURSOR_RIGHT_LINUX)
	{
	}
	else
	{
		printf("Unhandled keycode\n");
	}
	printf("keycode: %d\n", keycode);
	return (-1);
}

int	key_release(int keycode, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (keycode == R_LINUX)
	{
		(*ctrl)->key_r_pressed = false;
		puts("release!!");
	}
	return (0);
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
