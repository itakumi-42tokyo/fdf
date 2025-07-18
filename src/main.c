/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:59:45 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 11:45:09 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "utils.h"
#include "macro.h"
#include "struct.h"
#include "init.h"
#include <stddef.h>

// 一旦引数は１つだけとする。
// よくよく考えたら、マップのサイズはどのようにして確認すればよいのか？
int	main(int argc, char *argv[])
{
	t_control	*control;

	if (argc != 2)
		errmsg_exit(SYNTAX_ERROR);
	control = malloc(sizeof(t_control));
	if (control == NULL)
		errmsg_exit(MALLOC_ERROR);
	control->map = read_map(argv[1]);
	if (control->map == NULL)
	{
		free(control);
		errmsg_exit(MAP_READ_ERROR);
	}
	return (0);
}
