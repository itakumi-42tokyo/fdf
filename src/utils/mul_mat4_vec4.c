/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_mat4_vec4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 07:44:58 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/08 13:09:05 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"

// Matrix4x4 * Vector4 multiplication using union with anonymous struct
t_vector4_u	mul_mat4_vec4(const double mat[4][4], t_vector4_u vec)
{
	t_vector4_u	vec_new;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		vec_new.xyzw[i] = 0.0;
		while (j < 4)
		{
			vec_new.xyzw[i] += mat[i][j] * vec.xyzw[j];
			j++;
		}
		i++;
	}
	return (vec_new);
}

// int	main(void)
// {
// 	double mat[4][4] =
// 	{
// 		{2, 0, 0, 0},
// 		{1, 1, 0, 0},
// 		{0, 0, 1, 0},
// 		{0, 0, 0, 1}
// 	};
// 	t_vector4_u vec = {.x = 1, .y = 2, .z = 3, .w = 1};
// 	t_vector4_u vec_new = mul_mat4_vec4(mat, vec);

// 	printf("Input vector:  (%.1f, %.1f, %.1f, %.1f)\n",
// 	       vec.x, vec.y, vec.z, vec.w);
// 	printf("Output vector: (%.1f, %.1f, %.1f, %.1f)\n",
// 	       vec_new.x, vec_new.y, vec_new.z, vec_new.w);

// 	printf("Array access:  ");
// 	for (int i = 0; i < 4; i++)
// 	{
// 		printf("%.1f ", vec_new.xyzw[i]);
// 	}
// 	printf("\n");

// 	return (0);
// }
