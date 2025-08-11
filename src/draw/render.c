/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 18:18:53 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include "draw.h"
#include "exit.h"
#include "libft.h"
#include "macro.h"
#include "mlx.h"
#include "pipeline.h"
#include "projection.h"
#include "rotate.h"
#include "struct.h"
#include "translate.h"
#include "utils.h"
#include "view.h"
#include <stdbool.h>
#include <stdio.h>

// １．mapを変換する。(モデル変換)
// 2. 投影変換したマップをスケーリングする。（ビュー変換）
// ３．描画する　（カメラ変換）

// TODO
// 現状だと、描画パイプラインの動作が重いので、MVP行列計算で最適化したい

int	render(void *param)
{
	t_control	**ctrl;
	double		matrix[4][4];
	static bool	count_render = false;

	ctrl = (t_control **)param;
	if (ctrl == NULL || *ctrl == NULL)
		return (-1);
	mlx_clear_window((*ctrl)->mlx, (*ctrl)->win);
	ft_bzero((*ctrl)->data_addr, (*ctrl)->size_line * (*ctrl)->win_size_y);
	apply_rotate_matrix(matrix, (*ctrl)->total_angle_x, (*ctrl)->total_angle_y,
		0);
	if (PROJ == ISO)
		apply_iso_to_matrix(matrix);
	else if (PROJ == PERSP)
		apply_persp_to_matrix(matrix);
	apply_scale(matrix, (*ctrl)->zoom, (*ctrl)->zoom, (*ctrl)->zoom);
	apply_trans(matrix, (*ctrl)->total_trans_x, (*ctrl)->total_trans_y, 0);
	apply_mvp(*ctrl, matrix);
	if (count_render == false || (*ctrl)->key_r_pressed == true)
	{
		auto_fit_scale(*ctrl, (*ctrl)->zoom);
		count_render = true;
	}
	hook_bla(param);
	mlx_put_image_to_window((*ctrl)->mlx, (*ctrl)->win, (*ctrl)->img, 0, 0);
	return (0);
}
