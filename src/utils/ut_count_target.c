/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_count_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:38:32 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 17:43:36 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ut_count_target(char *str, char target)
{
	int	count;

	if (str == NULL)
		return (-1);
	count = 0;
	while (*str != '\0')
	{
		if (*str == target)
			count++;
		str++;
	}
	return (count);
}
