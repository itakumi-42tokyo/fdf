/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:00:52 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/18 11:30:44 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

// mapはおそらく方形と捉えて良さそう。
typedef struct s_control
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size_x;
	int		size_y;
	char	*title;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*data_addr;
	t_point	**map; // 2D配列のポインタ
	int		map_width; // マップの幅
	int		map_height; // マップの高さ
}	t_control;

#endif
