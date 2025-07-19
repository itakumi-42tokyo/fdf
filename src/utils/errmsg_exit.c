/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:59:17 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/19 18:06:16 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	errmsg_exit(const char *msg)
{
	ft_putstr_fd((char *)msg, 2);
	exit(EXIT_FAILURE);
}
