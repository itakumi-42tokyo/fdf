/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:11:38 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 17:07:00 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include "struct.h"

void	apply_scale(double matrix[4][4], double x, double y, double z)
{
	const double	matrix_scale[4][4] = {\
		{x, 0, 0, 0}, \
		{0, y, 0, 0}, \
		{0, 0, z, 0}, \
		{0, 0, 0, 1}};
	double			matrix_copy[4][4];
	int				i;
	int				j;

	if (matrix == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix_copy[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
	mul_4x4_mat(matrix_scale, matrix_copy, matrix);
}
