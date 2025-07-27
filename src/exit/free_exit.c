/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:13:23 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/27 21:29:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// XXX
#include <stdio.h>

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "struct.h"
#include "utils.h"

void	free_exit(t_control **ctrl)
{
	if (ctrl == NULL || *ctrl == NULL)
		(ft_putstr_fd("invalid argument: ctrl", 2), exit(EXIT_FAILURE));
	if ((*ctrl)->img != NULL)
		mlx_destroy_image((*ctrl)->mlx, (*ctrl)->img);
	mlx_destroy_window((*ctrl)->mlx, (*ctrl)->win);
	mlx_loop_end((*ctrl)->mlx);
	mlx_destroy_display((*ctrl)->mlx);
	free((*ctrl)->mlx);
	free_2d((void **)((*ctrl)->map));
	free_2d((void **)((*ctrl)->iso_map));
	free_2d((void **)((*ctrl)->persp_map));
	free((*ctrl));
	exit(EXIT_SUCCESS);
}
