/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:02:53 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 18:12:14 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "struct.h"

void	init_control(t_control *control)
{
	control->mlx = NULL;
	control->win = NULL;
	control->img = NULL;
	
}
