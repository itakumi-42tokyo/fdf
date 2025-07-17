/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 04:14:11 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/17 18:46:21 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro.h"
#include "mlx.h"
#include <stdlib.h>

int key_hook(int keycode, void *param)
{
	void	**p;
	void	*mlx;
	void	*win;
	void	*img;

	p = (void **)param;
	mlx = p[0];
	win = p[1];
	img = p[2];
	if (keycode == ESC_MACOS || keycode == ESC_LINUX)
	{
		mlx_destroy_image(mlx, img);
		mlx_destroy_window(mlx, win);
		mlx_loop_end(mlx);
		mlx_destroy_display(mlx);
		free(mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == X_MACOS || keycode == X_LINUX)
	{
		mlx_destroy_image(mlx, img);
		mlx_destroy_window(mlx, win);
		mlx_loop_end(mlx);
		mlx_destroy_display(mlx);
		free(mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// int	main(void)
// {
// 	void	*mlx = mlx_init();
// 	void	*win = mlx_new_window(mlx, 900, 900, "window01");
// 	void	*param[3] = {mlx, win, NULL};
// 	mlx_key_hook(win, key_hook, param);
// 	mlx_loop(mlx);
// 	return (0);
// }
