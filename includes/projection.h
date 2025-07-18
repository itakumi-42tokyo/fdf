/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:08:01 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/19 17:14:11 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "struct.h"

void	iso_proj(t_control *ctrl);
void	persp_proj(t_control *ctrl);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

#endif
