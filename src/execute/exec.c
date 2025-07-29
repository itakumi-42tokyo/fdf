/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:38:55 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/29 14:17:30 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdlib.h>
#include "mlx.h"
#include "macro.h"
#include "struct.h"
#include "draw.h"
#include "key.h"
#include "mouse.h"

// 描画する線をどのように決定するのか？
// 実際はマスクは(1L << 0) のような指定をしたほうが良さそう
void	exec(t_control **ctrl)
{
	void	*param = (void *)ctrl;

	mlx_expose_hook((*ctrl)->win, render, param);
	mlx_hook((*ctrl)->win, KeyPress, KeyPressMask, key_press, param);
	mlx_hook((*ctrl)->win, MotionNotify, PointerMotionMask, mouse_move, param);
	mlx_hook((*ctrl)->win, ButtonPress, ButtonPressMask, mouse_press, param);
	mlx_hook((*ctrl)->win, ButtonRelease, ButtonReleaseMask, mouse_release, param);
	mlx_hook((*ctrl)->win, DestroyNotify, StructureNotifyMask, close_window, param);
	mlx_loop((*ctrl)->mlx);
}
