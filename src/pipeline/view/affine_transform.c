/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:34:26 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/26 13:15:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "view.h"

void compute_affine_matrix(double scale, double tx, double ty, double matrix[3][3])
{
    // [ s  0 tx ]
    // [ 0  s ty ]
    // [ 0  0  1 ]
    matrix[0][0] = scale; matrix[0][1] = 0.0;   matrix[0][2] = tx;
    matrix[1][0] = 0.0;   matrix[1][1] = scale; matrix[1][2] = ty;
    matrix[2][0] = 0.0;   matrix[2][1] = 0.0;   matrix[2][2] = 1.0;
}

void apply_affine(const double matrix[3][3], int x, int y, int *out_x, int *out_y)
{
    double nx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2];
    double ny = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2];
    *out_x = (int)round(nx);
    *out_y = (int)round(ny);
}
