/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/19 18:03:57 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "macro.h"
#include "libft.h"
#include "struct.h"
#include "utils.h"

void	init_mlx(t_control *ctrl)
{
	ctrl->mlx = mlx_init();
	if (ctrl->mlx == NULL)
		(errmsg_exit(FAILED_MLX_INIT));
	ctrl->win = mlx_new_window(ctrl->mlx, ctrl->size_x, ctrl->size_y, ctrl->title);
	if (ctrl->win == NULL)
	{
		mlx_destroy_display(ctrl->mlx);
		free(ctrl->mlx);
		errmsg_exit(FAILED_MLX_WIN);
	}
}
