/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_atoi_with_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:16:48 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/26 13:23:20 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "utils.h"

// check if nptr does'nt have string and any forbit sign and overflow underflow
int	ut_atoi_with_check(const char *nptr, int *check)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ut_isspace(*nptr))
		nptr++;
	if (ut_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + *nptr - '0';
		if (sign == 1 && result > INT_MAX)
			return (*check = -1, -1);
		if (sign == -1 && (sign * result) < INT_MIN)
			return (*check = -1, -1);
		nptr++;
	}
	if (*nptr == ',')
		return (*check = 1, sign * (int)result);
	if (*nptr != '\0')
		return (*check = -1, -1);
	return (sign * (int)result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char *argv = "123";
// 	bool		error = false;
// 	int	num = ut_atoi_with_error(argv, &error);
// 	printf("num: %d\n", num);
// 	return (0);
// }
