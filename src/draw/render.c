/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/31 22:10:16 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <mlx.h>
#include "struct.h"
#include "view.h"
#include "draw.h"
#include "macro.h"
#include "projection.h"
#include "exit.h"

// １．mapを変換する。
// 2. 投影変換したマップをスケーリングする。
// ３．描画する

int	render(void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	mlx_clear_window((*ctrl)->mlx, (*ctrl)->win);
	if (PROJ == ISO)
	{
		if (iso_proj(*ctrl) == -1)// freeするか、値だけ、上書きしないといけない。
			free_exit(ctrl);
	}
	else if (PROJ == PERSP)
	{
		if (persp_proj(*ctrl) == -1)
			free_exit(ctrl);
	}
	puts("yes");
	auto_fit_scale((*ctrl), (*ctrl)->zoom);
	if (hook_bla(param) == -1)
		return (-1);
	return (0);
}
