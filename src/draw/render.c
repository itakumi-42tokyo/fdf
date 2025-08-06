/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 07:49:25 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <mlx.h>
#include "libft.h"
#include "struct.h"
#include "view.h"
#include "draw.h"
#include "macro.h"
#include "projection.h"
#include "exit.h"
#include "utils.h"
#include "rotate.h"

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
	// 1) イメージバッファをゼロクリア
	ft_bzero((*ctrl)->data_addr, (*ctrl)->size_line * (*ctrl)->win_size_y);
	// 2) 各種マップ更新・投影
	copy_map(*ctrl);
	// apply_3d_scale(*ctrl, (*ctrl)->zoom);
	calc_euler(*ctrl, (*ctrl)->total_angle_x, (*ctrl)->total_angle_y, 0);
	if (PROJ == ISO)
		iso_proj(*ctrl);
	else
		persp_proj(*ctrl);
	printf("zoom: %f\n", (*ctrl)->zoom);
	auto_fit_scale(*ctrl, (*ctrl)->zoom);
	// apply_viewport_transform(*ctrl);
	// 3) 描画ルーチンは img_data に直接書き込むように改修済み
	hook_bla(param);
	// 4) 最後にウィンドウへ一度だけ転送
	mlx_put_image_to_window((*ctrl)->mlx, (*ctrl)->win, (*ctrl)->img, 0, 0);
	return (0);
}
