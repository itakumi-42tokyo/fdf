/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:27:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 17:27:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "utils.h"

// static bool	is_delim(char a, char delim)
// {
// 	if (a == delim)
// 		return (true);
// 	return (false);
// }

// it is possible to swich this function.
int	ut_count_words(const char *str)
{
	bool	in_word;
	int		count;

	if (str == NULL)
		return (-1);
	in_word = false;
	count = 0;
	while (*str != '\0')
	{
		if (ut_isspace(*str) == true)
			in_word = false;
		if (in_word == false && ut_isspace(*str) == false)
		{
			in_word = true;
			count++;
		}
		str++;
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "fa a g   afdafa h ";
// 	int count = ut_count_words(str, ' ');
// 	printf("count: %d\n", count);
// 	return (0);
// }
