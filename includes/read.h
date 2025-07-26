/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:07:34 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 13:07:52 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

#include "struct.h"

int		atoi_base_with_check(const char *nptr, const char *table, int *check);
t_point	**read_map(t_control *control, char *file_path);
int		calc_row(const char *line);

#endif
