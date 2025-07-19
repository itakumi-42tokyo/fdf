/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:45 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/19 18:19:39 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "utils.h"
#include "macro.h"
#include "struct.h"
#include "init.h"
#include "projection.h"
#include <stddef.h>

// 一旦引数は１つだけとする。
// よくよく考えたら、マップのサイズはどのようにして確認すればよいのか？
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
	iso_proj(control);

	return (0);
}
