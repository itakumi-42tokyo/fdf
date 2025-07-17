/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/17 18:07:28 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "macro.h"
#include  <stddef.h>
#include <unistd.h>
#include "libft.h"

void	init(int size_x, int size_y, char *title)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (mlx == NULL)
		(ft_putstr_fd(2, FAILED_MLX_INIT), exit(1));
	win = mlx_new_window(mlx, size_x, size_y, title);
	if (win == NULL)
	{
		
	}

}
