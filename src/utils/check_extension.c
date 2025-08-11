/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:19:43 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/11 14:52:24 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "struct.h"
#include "macro.h"

int	check_extention(char *file_path, char *ext_correct)
{
	char	*file_ext;
	int		file_ext_len;
	int		ext_len;

	file_ext = ft_strrchr(file_path, ".");
	if (file_ext == NULL)
		return (-1);
	file_ext_len = ft_strlen(file_ext);
	ext_len = ft_strlen(ext_correct);
	if (file_ext_len != ext_len)
		return (-1);
	if (ft_strncmp(file_ext, ext_correct, ext_len) != 0)
		return (-1);
	return (0);
}
