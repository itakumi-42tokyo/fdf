/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:00:04 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/07 08:27:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

void	init0_control(t_control *control);
void	init_control(t_control *control);
void	init_mlx(t_control *ctrl);
int		alloc_proj(t_control *ctrl);

#endif
