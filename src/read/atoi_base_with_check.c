/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_with_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:31:01 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 13:14:51 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include "libft.h"
#include "struct.h"
#include "macro.h"
#include "utils.h"

static bool	move_pointer(const char **nptr)
{
	if (nptr == NULL || *nptr == NULL || **nptr == '\0')
		return (true);
	if (**nptr == '0')
		(*nptr)++;
	if (**nptr == 'x')
		(*nptr)++;
	if (**nptr == '\0')
		return (true);
	return (false);
}

static int	get_unit_digit(const char *table, char digit)
{
	int			count;
	const char d = (const char)digit;

	if (table == NULL)
		return (-1);
	count = 0;
	while (*table != '\0')
	{
		if (*table == d)
			return (count);
		table++;
		count++;
	}
	return (-1);
}

// 0xはある前提だが、なくても動くようにしようか。？
//　先頭のZ座標の数を飛ばさないと行けない。->','まで、ポインタを飛ばすという実装で良いのだろうか。
// から文字の場合は、から文字飛ばしているからいいでしょう理論でいこう
int	atoi_base_with_check(const char *nptr, const char *table, int *check)
{
	long long	result;
	int			base_len;

	result = 0;
	if (nptr == NULL || *nptr == '\0' || table == NULL || check == NULL)
		return (*check = -1, -1);
	nptr = ft_strchr(nptr, ',');
	if (*nptr != ',')
		return (*check = -1, -1);
	nptr++;
	base_len = ft_strlen(table);
	if (move_pointer(&nptr) == true)
		return (*check = -1, -1);
	while (get_unit_digit(table, *nptr) != -1)
	{
		result = result * base_len + get_unit_digit(table, *nptr);
		if (result > INT_MAX)
			return (*check = -1, -1);
		if (result < INT_MIN)
			return (*check = -1, -1);
		nptr++;
	}
	if (*nptr != '\0')
		return (*check = -1, -1);
	return ((int)result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	bool error = false;
// 	int result = atoi_base_with_error(" 0x1233", "0123456789ABCDEF", &error);
// 	if (error == true)
// 	{
// 		puts("error!");
// 		return (1);
// 	}
// 	printf("%d\n", result);
// 	return (0);
// }
