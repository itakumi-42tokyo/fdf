/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:08:01 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/21 17:38:54 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "struct.h"

int		iso_proj(t_control *ctrl);
int		persp_proj(t_control *ctrl);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

#endif
