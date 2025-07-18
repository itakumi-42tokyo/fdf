/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:19 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 11:47:33 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "macro.h"
#include "libft.h"
#include "utils.h"
#include <fcntl.h>
#include <stddef.h>

//　改行ごとにチェックする関数にするべきか？
int	parse_token(t_point **map, char **tokens, const int y)
{
	int		i;
	bool	error;

	if (map == NULL || tokens == NULL)
		return (-1);
	map[y] = malloc(sizeof(t_point) * MAP_SIZE_X);
	if (map[y] == NULL)
		return (-1);
	error = false;
	i = 0;
	while (tokens[i] != NULL)
	{
		(map[y][i]).x = i;
		(map[y][i]).y = y;
		(map[y][i]).z = ut_atoi_with_error(tokens[i], &error);
		if (error == true)
			return (-1);
		i++;
	}
}
// 整数はどの型までを許容するか？　整数で来ない場合もあるのかな？
// ut_atoi_with_errorは、数字以外が入力されているときも反応する。


// ここでlineを解析して、必要な情報を抽出する
// 例えば、空白で区切られた整数を取得するなど
// 解析後はlineを解放する
t_point *parse_map(int fd)
{
	t_point	**map;
	char 	**tokens;
	char	*line;
	int		y;

	map = malloc(sizeof(t_point *) * MAP_SIZE_Y);
	if (map == NULL)
		return (NULL);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		tokens = ft_split(line, ' ');
		if (tokens == NULL)
			return (free(line), free_2d((void **)map), NULL);
		if (parse_tokens(map, tokens, y) == -1)
			return (free(line), free_2d((void **)tokens), free_2d((void **)map), NULL);
		free_2d((void **)tokens);
		free(line);
		y++;
	}
	return (map);
}

int	calc_map_size(int fd, int *width, int *height)
{
	int	i;

	if (width == NULL || height == NULL)
		return (-1);

}

t_point	**read_map(char *file_path)
{
	t_point		**map;
	int			fd;

	if (file_path == NULL)
		return (NULL);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
	{
		perror(file_path);
		return (NULL);
	}
	map = parse_map(fd);
	if (map == NULL)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
