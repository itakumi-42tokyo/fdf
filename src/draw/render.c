/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:13:20 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/29 19:53:27 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <mlx.h>
#include "struct.h"
#include "view.h"
#include "draw.h"

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
	auto_fit_scale((*ctrl), (*ctrl)->zoom);
	if (hook_bla(param) == -1)
		return (-1);
	return (0);
}
