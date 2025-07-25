/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:13:23 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/20 19:41:03 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "struct.h"

void	free_exit(t_control **ctrl)
{
	if (ctrl == NULL || *ctrl == NULL)
		(ft_putstr_fd("invalid argument: ctrl", 2), exit(EXIT_FAILURE));
	mlx_destroy_image((*ctrl)->mlx, (*ctrl)->img);
	mlx_destroy_window((*ctrl)->mlx, (*ctrl)->win);
	mlx_loop_end((*ctrl)->mlx);
	mlx_destroy_display((*ctrl)->mlx);
	free((*ctrl)->mlx);
	exit(EXIT_SUCCESS);
}
