/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:16:57 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 16:59:47 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

#include "struct.h"

double	**create_rotate_matrix(t_control *ctrl, double deg_x, double deg_y, double deg_z);
int		calc_euler(t_control *ctrl, double deg_x, double deg_y, double deg_z);
int		calc_quat(t_control *ctrl);
int		calc_matrix(t_control *ctrl);
void	euler_to_quat(t_control *ctrl);
void	quat_to_matrix(t_control *ctrl);

#endif
