/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:00:04 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/31 21:26:23 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

void	init_control(t_control *control);
void	init_mlx(t_control *ctrl);
int		alloc_proj(t_control *ctrl);

#endif
