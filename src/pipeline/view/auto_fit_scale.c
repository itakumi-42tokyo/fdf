/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_fit_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:34:39 by tigarashi         #+#    #+#             */
/*   Updated: 2025/08/12 01:29:04 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "macro.h"
#include "struct.h"
#include "view.h"
#include <limits.h>
#include <math.h>
#include <unistd.h>

static void	judge_max_min(int ix, int iy, int min_xy[2], int max_xy[2])
{
	if (ix < min_xy[0])
		min_xy[0] = ix;
	if (iy < min_xy[1])
		min_xy[1] = iy;
	if (ix > max_xy[0])
		max_xy[0] = ix;
	if (iy > max_xy[1])
		max_xy[1] = iy;
}

static void	init_max_min(int min_xy[2], int max_xy[2])
{
	min_xy[0] = INT_MAX;
	min_xy[1] = INT_MAX;
	max_xy[0] = INT_MIN;
	max_xy[1] = INT_MIN;
}

static void	subs_xy(int *ix, int *iy, int x, int y)
{
	*ix = x;
	*iy = y;
}

// zはスケーリングしなくてよいのか。
static void	calc_bounds_local(t_control *ctrl, int min_xy[2], int max_xy[2])
{
	int	i;
	int	j;
	int	ix;
	int	iy;

	i = 0;
	while (i < ctrl->map_height)
	{
		j = 0;
		while (j < ctrl->map_width)
		{
			if (PROJ == ISO)
				subs_xy(&ix, &iy,
					ctrl->iso_map[i][j].iso_x, ctrl->iso_map[i][j].iso_y);
			else if (PROJ == PERSP)
				subs_xy(&ix, &iy, ctrl->persp_map[i][j].persp_x,
					ctrl->persp_map[i][j].persp_y);
			else
				ft_putstr_fd(ERROR_PROJ_MACRO, STDERR_FILENO);
			judge_max_min(ix, iy, min_xy, max_xy);
			j++;
		}
		i++;
	}
}

// 最終的に min_xy もゼロ原点に移してから中央に配置
// 拡大縮小のオーバーフロー処理をしないといけない。
void	auto_fit_scale(t_control *ctrl, float fit_ratio)
{
	int		min_xy[2];
	int		max_xy[2];
	double	w;
	double	h;
	double	sx_sy[2];

	init_max_min(min_xy, max_xy);
	calc_bounds_local(ctrl, min_xy, max_xy);
	w = max_xy[0] - min_xy[0];
	h = max_xy[1] - min_xy[1];
	if (w <= 0)
		w = 1;
	if (h <= 0)
		h = 1;
	sx_sy[0] = (ctrl->win_size_x * (double)fit_ratio) / w;
	sx_sy[1] = (ctrl->win_size_y * (double)fit_ratio) / h;
	ctrl->scale = fmin(sx_sy[0], sx_sy[1]);
	ctrl->offset_x = (ctrl->win_size_x - ctrl->scale * w) / 2 - min_xy[0]
		* ctrl->scale;
	ctrl->offset_y = (ctrl->win_size_y - ctrl->scale * h) / 2 - min_xy[1]
		* ctrl->scale;
}
