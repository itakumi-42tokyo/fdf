/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:50:56 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/20 19:00:37 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	bla(int x0, int y0, int x1, int y1, void *mlx, void *win);
void	dda(int x1, int y1, int x2, int y2, void *mlx, void *win);
void	wla(int x0, int y0, int x1, int y1, void *mlx, void *win, void *img);
int		hook_bla(void *param);
int		hook_dda(void *param);
int		hook_wla(void *param);

#endif
