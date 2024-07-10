/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tags.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:44:46 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:41:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_tags_init(t_tag *tag)
{
	tag->start = tag->i;
	tag->minus = 0;
	tag->plus = 0;
	tag->space = 0;
	tag->hastag = 0;
	tag->zero = ' ';
	tag->wi = 0;
	tag->pre = -1;
}

void	ft_tags_insert(char *s, t_tag *tag)
{
	if (!ft_strchr("cspdiuxX%", s[tag->i]))
		ft_putnotag(s, tag);
	else if (s[tag->i] == 'c')
		ft_putctag(tag);
	else if (s[tag->i] == 's')
		ft_putstag(tag);
	else if (s[tag->i] == 'i' || s[tag->i] == 'd')
		ft_putdtag(tag);
	else if (s[tag->i] == 'x')
		ft_putxtag(tag, 0);
	else if (s[tag->i] == 'X')
		ft_putxtag(tag, 1);
	else if (s[tag->i] == 'p')
		ft_putptag(tag);
	else if (s[tag->i] == '%')
		ft_putchar_len('%', &tag->len);
	else if (s[tag->i] == 'u')
		ft_pututag(tag);
}

static int	nbinfront(char *s)
{
	int	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

void	ft_tags_def(char *src, t_tag *tag)
{
	while (ft_strchr("-+ #0", src[++tag->i]))
	{
		if (src[tag->i] == '-')
			tag->minus++;
		if (src[tag->i] == '+')
			tag->plus++;
		if (src[tag->i] == ' ')
			tag->space++;
		if (src[tag->i] == '#')
			tag->hastag++;
		if (src[tag->i] == '0')
			tag->zero = '0';
	}
	if (ft_isdigit(src[tag->i]))
	{
		tag->wi = ft_atoi(&src[tag->i]);
		tag->i += nbinfront(&src[tag->i]);
	}
	if (src[tag->i] == '.')
	{
		tag->pre = ft_atoi(&src[tag->i + 1]);
		tag->i += nbinfront(&src[tag->i + 1]) + 1;
	}
}
