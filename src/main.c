/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:45 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 20:56:55 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include "utils.h"
#include "macro.h"
#include "struct.h"
#include "init.h"
#include "projection.h"
#include "execute.h"
#include "free.h"
#include "draw.h"
#include "read.h"
#include "view.h"

// 一旦引数は１つだけとする。
// read_mapでcontrolのmapに格納するべきかそれとも、返り値で格納するべきか？
int	main(int argc, char *argv[])
{
	t_control	*control;

	if (argc != 2)
		errmsg_exit(SYNTAX_ERROR);
	control = malloc(sizeof(t_control));
	if (control == NULL)
		errmsg_exit(MALLOC_ERROR);
	init_control(control);
	control->map = read_map(control, argv[1]);
	if (control->map == NULL)
	{
		free(control);
		errmsg_exit(MAP_READ_ERROR);
	}
	init_mlx(control);
	if (persp_proj(control) == -1)
		free_exit(&control);
	auto_fit_scale(control, 0.9);
	exec(&control);
	return (0);
}
