/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 18:01:56 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "macro.h"
#include  <stddef.h>
#include <unistd.h>
#include "libft.h"

void	init_mlx(int size_x, int size_y, char *title)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (mlx == NULL)
		(errmsg_exit(FAILED_MLX_INIT));
	win = mlx_new_window(mlx, size_x, size_y, title);
	if (win == NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		errmsg_exit(FAILED_MLX_WIN);
	}
}
