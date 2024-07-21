/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:37:08 by aautin            #+#    #+#             */
/*   Updated: 2024/02/26 19:43:22 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 142
# endif

# ifndef FDS_NUMBER
#  define FDS_NUMBER 512
# endif

// get_next_line_utils_bonus.c
char	*string_chr(char *str, char letter);

// get_next_line_bonus.c
char	*string_join(char *s1, char *s2, char flag);
void	set_string_after_newline(char *buffer);
char	*turn_string_into_firstline(char *temp);
char	*get_next_line(int fd);

#endif