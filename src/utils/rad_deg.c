/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_deg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:42:40 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/19 17:11:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "macro.h"

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

double	rad_to_deg(double rad)
{
	return (rad * 180 / M_PI);
}
