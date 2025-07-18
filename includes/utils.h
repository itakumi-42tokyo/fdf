/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 05:32:36 by tigarashi         #+#    #+#             */
/*   Updated: 2025/07/18 10:57:09 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
// bool

int		my_abs(int n);
int		swap(int *a, int *b);
void	errmsg_exit(const char *msg);
void	free_2d(void **array);
int		ut_atoi_with_error(const char *nptr, bool *error);
int		ut_issign(int c);
int		ut_isspace(int c);

#endif
