/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:45 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/17 20:41:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 5000, 5000, "FDF");
	mlx_loop(mlx);
	return (0);
}
