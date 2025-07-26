/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 04:14:11 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/26 21:59:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include <linux/input-event-codes.h>
#include <stdlib.h>
#include "mlx.h"
#include "struct.h"
#include "macro.h"
#include "free.h"


// macOS 対応は要検討
int key_hook(t_control **ctrl, int keycode)
{
	if (keycode == KEY_ESC)
		free_exit(ctrl);
	if (keycode == KEY_MINUS)
		return (0);
	printf("keycode: %d\n", keycode);
	return (-1);
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
