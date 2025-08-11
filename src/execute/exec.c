/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:38:55 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 13:38:43 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdlib.h>
#include "mlx.h"
#include "macro.h"
#include "draw.h"
#include "key.h"
#include "mouse.h"
#include "struct.h"
#include "exit.h"

// 描画する線をどのように決定するのか？
// 実際はマスクは(1L << 0) のような指定をしたほうが良さそう
void	exec(t_control **ctrl)
{
	void	*param;
	int		ret;

	param = (void *)ctrl;
	ret = mlx_expose_hook((*ctrl)->win, render, param);
	if (ret == -1)
		free_exit(ctrl);
	mlx_hook((*ctrl)->win, KeyPress, KeyPressMask, key_press, param);
	mlx_hook((*ctrl)->win, KeyRelease, KeyReleaseMask, key_release, param);
	mlx_hook((*ctrl)->win, MotionNotify, PointerMotionMask, mouse_move, param);
	mlx_hook((*ctrl)->win, ButtonPress, ButtonPressMask, mouse_press, param);
	mlx_hook((*ctrl)->win, ButtonRelease, ButtonReleaseMask, mouse_release, param);
	mlx_hook((*ctrl)->win, DestroyNotify, StructureNotifyMask, close_window, param);
	mlx_loop((*ctrl)->mlx);
}
