/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:34:09 by aautin            #+#    #+#             */
/*   Updated: 2023/12/29 15:59:00 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_tag
{
	va_list	vaarg;
	int		len;
	int		i;
	int		start;
	char	minus;
	char	plus;
	char	space;
	char	hastag;
	char	zero;
	int		wi;
	int		pre;
}	t_tag;

void	ft_putcharnb_len(char a, int nb, int *len);
void	ft_putchar_len(int a, int *len);
void	ft_putctag(t_tag *tag);

void	ft_tags_init(t_tag *tag);
void	ft_tags_def(char *src, t_tag *tag);
void	ft_tags_insert(char *src, t_tag *tag);

void	ft_putstr_len(char *str, int *printed);
void	ft_putstag(t_tag *tag);

void	ft_pre_str(int *nb, t_tag *tag, int strlen);
void	ft_strlcat_c(char *dest, char src);
void	ft_putnotag(char *s, t_tag *tag);
size_t	ft_nblen(size_t i, int base);
int		ft_printf(const char *s, ...);

void	ft_puthexa_len(unsigned int nb, int *len, int maj, char *str);
void	ft_putxtag(t_tag *tag, int maj);

void	ft_pututag(t_tag *tag);

void	ft_putdtag(t_tag *tag);

void	ft_putphexa_len(size_t nb, int *len, int maj, char *str);
void	ft_insertptag(t_tag *tag, int len, char *str);
void	ft_putptag(t_tag *tag);

#endif