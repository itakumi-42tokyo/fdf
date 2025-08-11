/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:19 by itakumi           #+#    #+#             */
/*   Updated: 2025/08/12 03:04:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// XXX
#include "get_next_line.h"
#include "libft.h"
#include "macro.h"
#include "read.h"
#include "struct.h"
#include "utils.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

// 16進数にも対応させないといけない
//　改行ごとにチェックする関数にするべきか？
// colorは別で、処理するべきか？

static void	substitute_map(t_point **map, int i, int y, int token)
{
	(map[y][i]).x = i;
	(map[y][i]).y = y;
	(map[y][i]).z = token;
}

int	parse_tokens(t_point **map, char **tokens, const int y, const int width)
{
	int	i;
	int	token;
	int	check;

	if (map == NULL || tokens == NULL)
		return (-1);
	map[y] = malloc(sizeof(t_point) * width);
	if (map[y] == NULL)
		return (-1);
	i = 0;
	while (tokens[i] != NULL)
	{
		check = 0;
		token = ut_atoi_with_check(tokens[i], &check);
		if (check == 1)
			(map[y][i]).color
				= atoi_base_with_check(tokens[i], HEX_TABLE, &check);
		else
			(map[y][i]).color = 0xFFFFFF;
		if (check == -1)
			return (-1);
		substitute_map(map, i, y, token);
		i++;
	}
	return (0);
}
// 整数はどの型までを許容するか？　整数で来ない場合もあるのかな？
// ut_atoi_with_cheは、数字以外が入力されているときも反応する。

// ここでlineを解析して、必要な情報を抽出する
// 例えば、空白で区切られた整数を取得するなど
// 解析後はlineを解放する
// width + 1 にしなくてもよいのかな？
t_point	**parse_map(int fd, int width, int height)
{
	t_point	**map;
	char	**tokens;
	char	*line;
	int		y;

	map = malloc(sizeof(t_point *) * (height + 1));
	if (map == NULL)
		return (NULL);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tokens = ut_split(line, SEP);
		if (tokens == NULL)
			return (free(line), free_2d((void **)map), NULL);
		if (parse_tokens(map, tokens, y, width) == -1)
			return (free(line), free_2d((void **)tokens), free_2d((void **)map),
				NULL);
		(free(line), free_2d((void **)tokens));
		y++;
	}
	map[y] = NULL;
	return (map);
}

// TODO
// FIXME
// XXX
// 改行の数で、heightを決定してもよいのだろうか？
// it is needed to go back and put it in point if color information is contained
// 0x が入っていないものを単語としてカウントすることにしよう。
int	calc_map_size(t_control *control, char *file_path)
{
	int		fd;
	char	*line;

	if (control == NULL || file_path == NULL)
		return (-1);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
		return (perror(file_path), -1);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), -1);
	control->map_width = calc_row(line);
	control->map_height += 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		control->map_height += 1;
	}
	return (close(fd), 0);
}
// 改行だけでheightを確認するのは怪しいので、他の方法はないかな？
// １．数字の直後の改行を見て、判断する。
// ２．

t_point	**read_map(t_control *control, char *file_path)
{
	t_point	**map;
	int		fd;

	if (file_path == NULL || check_extention(file_path,
			CORRECT_FILE_EXTENSION) == -1)
		return (NULL);
	if (calc_map_size(control, file_path) == -1)
		return (NULL);
	fd = open(file_path, O_RDONLY | __O_CLOEXEC);
	if (fd == -1)
	{
		perror(file_path);
		return (NULL);
	}
	map = parse_map(fd, control->map_width, control->map_height);
	if (map == NULL)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
