/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:19 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/17 20:25:09 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include <fcntl.h>
#include <stddef.h>

//　改行ごとにチェックする関数にするべきか？

int	parse_token(char **tokens)
{

}

t_control *parse_map(int fd)
{
	t_point	**map;
	char 	**tokens;
	char	*line;

	map = mallox(sizeof(t_point *) * )
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		// ここでlineを解析して、必要な情報を抽出する
		// 例えば、空白で区切られた整数を取得するなど
		tokens = ft_split(line, ' ');
		if (tokens == NULL)
		{

		}
		if (parse_tokens(tokens) == -1)
		{

		}
		// 解析後はlineを解放する
		free(line);
	}
	return (map);
}

int	check_map(char *file_path)
{
	t_point	**map;
	int		fd;


	if (file_path == NULL)
		return (-1);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
	{
		perror(file_path);
		return (-1);
	}
	map = parse_map(fd);
	if (map == NULL)
	{
		close(fd);
		return (-1);
	}
}
