/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:36:21 by tigarashi         #+#    #+#             */
/*   Updated: 2025/08/07 13:05:57 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "struct.h"

void    compute_affine_matrix(double scale, double tx, double ty, double matrix[3][3]);
void    apply_affine(const double matrix[3][3], int x, int y, int *out_x, int *out_y);
void    auto_fit_scale(t_control *ctrl, float fit_ratio);

#endif
