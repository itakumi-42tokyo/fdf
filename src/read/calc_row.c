/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:19:34 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 10:26:06 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft.h"
#include "macro.h"
#include "struct.h"

int	calc_row(const char *line)
{
	bool	in_word;
	int		count;

	if (line == NULL)
		return (-1);
	in_word = false;
	count = 0;
	while (*line != '\0')
	{
		if (ut_isspace(*line) == true)
			in_word = false;
		if (in_word == false && ut_isspace(*line) == false)
		{
			in_word = true;
			if (ft_strncmp(line, COLOR_INFO, 2) != 0)
				count++;
		}
		line++;
	}
	return (count);
}
