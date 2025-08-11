/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 04:14:11 by tigarashi         #+#    #+#             */
/*   Updated: 2025/08/11 19:08:53 by itakumi          ###   ########.fr       */
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

static void	key_trans(int keycode, t_control **ctrl, void *param)
{
	if (keycode == W_LINUX)
	{
		(*ctrl)->total_trans_y--;
		render(param);
	}
	else if (keycode == A_LINUX)
	{
		(*ctrl)->total_trans_x--;
		render(param);
	}
	else if (keycode == S_LINUX)
	{
		(*ctrl)->total_trans_y++;
		render(param);
	}
	else if (keycode == D_LINUX)
	{
		(*ctrl)->total_trans_x++;
		render(param);
	}
	else
		write(2, ERROR_KEY, ft_strlen(ERROR_KEY));
	write(2, TRANSLATE, ft_strlen(TRANSLATE));
}

static void	key_reset(int keycode, t_control **ctrl, void *param)
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
	write(1, RESET_RENDER, ft_strlen(RESET_RENDER));
}

int	key_press(int keycode, void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	if (keycode == ESC_LINUX)
		free_exit(ctrl);
	else if (keycode == R_LINUX)
		key_reset(keycode, ctrl, param);
	else if (keycode == W_LINUX || keycode == A_LINUX || keycode == S_LINUX
		|| keycode == D_LINUX)
		key_trans(keycode, ctrl, param);
	else
		write(2, ERROR_KEY, ft_strlen(ERROR_KEY));
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
