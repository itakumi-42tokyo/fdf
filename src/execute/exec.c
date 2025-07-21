/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:38:55 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/21 18:10:25 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "macro.h"
#include "struct.h"
#include "draw.h"
#include "key.h"

// 描画する線をどのように決定するのか？
void	exec(t_control **ctrl)
{
	const void	*param = (void *)ctrl;

	mlx_expose_hook((*ctrl)->win, hook_bla, param);
	mlx_key_hook((*ctrl)->win, key_hook, param);
	mlx_loop((*ctrl)->mlx);
}
