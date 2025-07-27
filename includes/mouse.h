/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:31:18 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/27 15:51:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		close_window(void *param);

#endif
