/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul4x4_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 07:11:40 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/08 15:11:57 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	mul_4x4_mat(const double a[4][4], const double b[4][4], double result[4][4])
{
	double	tmp[4][4];
	int		i;
	int		j;
	int		k;

	// 行列の乗算
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[i][j] = 0.0; // 初期化
			k = 0;
			while (k < 4)
			{
				tmp[i][j] += a[i][k] * b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}

	// 結果をコピー
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}
