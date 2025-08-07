/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 18:35:10 by itakumi          ###   ########.fr       */
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

// １．mapを変換する。(モデル変換)
// 2. 投影変換したマップをスケーリングする。（ビュー変換）
// ３．描画する　（カメラ変換）

// TODO
// 現状だと、描画パイプラインの動作が重いので、MVP行列計算で最適化したい

int	render(void *param)
{
	t_control	**ctrl;
	double		**matrix;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	mlx_clear_window((*ctrl)->mlx, (*ctrl)->win);
	// 1) イメージバッファをゼロクリア
	ft_bzero((*ctrl)->data_addr, (*ctrl)->size_line * (*ctrl)->win_size_y);
	// 2) 各種マップ更新・投影
	matrix = create_rotate_matrix(*ctrl, (*ctrl)->total_angle_x, (*ctrl)->total_angle_y, 0);
	if (matrix == NULL)
		return (-1);
	// calc_euler(*ctrl, (*ctrl)->total_angle_y, (*ctrl)->total_angle_x, 0);
	if (PROJ == ISO)
		apply_iso_to_matrix(matrix);
	else if (PROJ == PERSP)
		apply_persp_to_matrix(matrix);
	// if (PROJ == ISO)
	// 	iso_proj(*ctrl);
	// else
	// 	persp_proj(*ctrl);
	auto_fit_scale(*ctrl, (*ctrl)->zoom);
	// 3) 描画ルーチンは img_data に直接書き込むように改修済み
	hook_bla(param);
	// 4) 最後にウィンドウへ一度だけ転送
	mlx_put_image_to_window((*ctrl)->mlx, (*ctrl)->win, (*ctrl)->img, 0, 0);
	return (0);
}
