/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:25:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/10 19:03:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include <stdio.h>

#include "struct.h"
#include "utils.h"

// 平行移動はどのような設計にしようか。
// ボタンが押されているときというのがあったはず，だからそのようなときに，連続して動くような仕様にする？
void	apply_trans(double matrix[4][4], double x, double y, double z)
{
	const double	matrix_trans[4][4] =
	{
		{1, 0, 0, x},
		{0, 1, 0, y},
		{0, 0, 1, z},
		{0, 0, 0, 1}
	};
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
	mul_4x4_mat(matrix_trans, matrix_copy, matrix);
}
