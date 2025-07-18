/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:00:04 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 18:51:15 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

void	init_control(t_control *control);
void	init_mlx(t_control *ctrl);
t_point	**read_map(t_control *control, char *file_path);

#endif
