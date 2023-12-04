/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:12:12 by kpires            #+#    #+#             */
/*   Updated: 2023/12/04 13:53:57 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*delete stdio*/
#include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_print_str(char *str);
int		ft_printchar(int c);
int		t_format(va_list args, const char format);

#endif