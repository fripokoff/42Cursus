/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:16:24 by apintus           #+#    #+#             */
/*   Updated: 2024/02/09 16:57:33 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd, int error);
char	*ft_fill(int fd, char *data);
char	*ft_extract_line(char *data);
char	*ft_update_data(char *old_data);
char	*ft_strjoin_gnl(char *data, char *buffer);
size_t	ft_strlen_gnl(char *str);
int		ft_strcontains(char *str, char c);

#endif
