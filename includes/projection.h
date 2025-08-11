/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:08:01 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 17:24:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "struct.h"

int		apply_persp_to_matrix(double marix[4][4]);
int		apply_iso_to_matrix(double matrix[4][4]);
int		iso_proj(t_control *ctrl);
int		apply_persp_to_matrix(double matrix[4][4]);
// int		persp_proj(t_control *ctrl);

#endif
