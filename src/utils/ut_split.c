/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:31:46 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/20 22:26:00 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static int	issep(char c, const char *sep)
{
	if (sep == NULL)
		return (-1);
	while (*sep != '\0')
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

static char	*cpy_word(const char *str, const char *sep)
{
	int		len;
	int		i;
	char	*cpy;

	if (str == NULL || sep == NULL)
		return (NULL);
	len = 0;
	while (str[len] && issep(str[len], sep) == 0)
		len++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = (char)str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int process(char **new, const char *str, const char *sep)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		while (*str && issep(*str, sep) == 1)
			str++;
		if (*str)
		{
			new[i] = cpy_word(str, sep);
			if (new[i] == NULL)
				return (-1);
			i++;
			while (*str && issep(*str, sep) == 0)
				str++;
		}
	}
	new[i] = NULL;
	return (0);
}

char	**ut_split(const char *str, const char *sep)
{
	char		**new;
	int			count;

	if (!str || *str == '\0' || sep == NULL)
		return (NULL);
	count = ut_count_words(str);
	new = malloc(sizeof(char *) * (count + 1));
	if (new == NULL)
		return (NULL);
	if (process(new, str, sep) == -1)
	{
		free_2d((void **)new);
		return (NULL);
	}
	return (new);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char *str = " sfsaetg	affa asdfasd	";
// 	const char *sep = " 	";
// 	char **split = ut_split(str, sep);
// 	while (*split != NULL)
// 		printf("%s\n", *split++);
// 	return (0);
// }
