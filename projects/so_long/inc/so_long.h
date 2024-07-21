/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:11:09 by kpires            #+#    #+#             */
/*   Updated: 2024/07/20 11:11:09 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "fcntl.h"
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;	

typedef struct s_settings
{
	t_pos	map_size;
	t_pos	win_size;
	t_pos	scr_size;
	char	**map;
}	t_settings;

char	**get_map_by_file(char *file_name);
void	exit_error(char *msg);
#endif