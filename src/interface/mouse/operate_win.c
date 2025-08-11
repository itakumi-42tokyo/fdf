/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:18:38 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 03:19:59 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "exit.h"

int	close_window(void *param)
{
	t_control	**ctrl;

	ctrl = (t_control **)param;
	free_exit(ctrl);
	return (-1);
}
