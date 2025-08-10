/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:36:21 by tigarashi         #+#    #+#             */
/*   Updated: 2025/08/10 18:42:16 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "struct.h"

void	apply_scale(double matrix[4][4], double x, double y, double z);
void    auto_fit_scale(t_control *ctrl, float fit_ratio);

#endif
