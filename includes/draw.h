/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:50:56 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 18:39:56 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

int		render(void *param);
void	bla(int xy1[2], int xy2[2], int color, t_control *ctrl);
// void	dda(int xy1[2], int xy2[2], int color, t_control *ctrl);
// void	wla(int p0[2], int p1[2], int color);
int		hook_bla(void *param);
int		hook_dda(void *param);
int		hook_wla(void *param);

#endif
