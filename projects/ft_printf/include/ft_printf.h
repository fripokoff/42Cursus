/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:02:36 by kpires            #+#    #+#             */
/*   Updated: 2023/12/11 15:03:59 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_str(char *str);
int		ft_printchar(int c, int *b);
int		ft_format(va_list args, const char format);
int		ft_putnbr(int nbr, int *b);
int		ft_putnbr_unsigned(unsigned int nbr, int *b);
int		ft_put_hex(unsigned int nbr, const char format, int *b);
int		ft_putptr(uintptr_t ptr, int *b);
#endif