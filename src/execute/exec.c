/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:38:55 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/28 19:11:27 by itakumi          ###   ########.fr       */
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
//
void	exec(t_control **ctrl)
{
	void	*param = (void *)ctrl;

	mlx_expose_hook((*ctrl)->win, hook_bla, param);
	mlx_hook((*ctrl)->win, KeyPress, KeyPressMask, key_press, param);
	mlx_hook((*ctrl)->win, MotionNotify, PointerMotionMask, mouse_move, param);
	mlx_hook((*ctrl)->win, MotionNotify, ButtonPressMask, mouse_press, param);
	mlx_hook((*ctrl)->win, MotionNotify, ButtonReleaseMask, mouse_release, param);
	mlx_hook((*ctrl)->win, DestroyNotify, StructureNotifyMask, close_window, param);
	mlx_hook((*ctrl)->win, Button4, ButtonPressMask, mouse_role_up, param);
	mlx_hook((*ctrl)->win, Button5, ButtonPressMask, mouse_role_down, param);
	mlx_loop((*ctrl)->mlx);
}
