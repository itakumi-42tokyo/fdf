/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:20:55 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/16 23:20:56 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

// Error messege
# define SYNTAX_ERROR "Usage: ./fdf <filename>\n"
# define MALLOC_ERROR "malloc error\n"
# define MAP_READ_ERROR "map read error\n"
# define FAILED_MLX_INIT "failed mix_init\n"
# define FAILED_MLX_WIN "failed mlx_window\n"

// keycode
# define ESC_MACOS 53
# define ESC_LINUX 65307
# define X_MACOS 7
# define X_LINUX 120

// window size
# define DEFAULT_WIN_SIZE_X 1000
# define DEFAULT_WIN_SIZE_Y 1000

// title
# define DEFAULT_TITLE "FDF"

// buffer size
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8192
# endif

# ifndef M_PI
# define M_PI 3.14159265359
# endif

# ifndef SEP
# define SEP " \t\n"
# endif

#endif
