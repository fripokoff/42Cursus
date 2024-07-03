/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:18 by aautin            #+#    #+#             */
/*   Updated: 2023/12/29 16:06:17 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/ft_printf.h"

void	ft_pre_str(int *nb, t_tag *tag, int strlen)
{
	if (tag->pre > strlen)
	{
		tag->wi -= tag->pre - strlen;
		(*nb)--;
	}
}

size_t	ft_nblen(size_t i, int base)
{
	size_t	len;

	len = 1;
	while (i / base)
	{
		i /= base;
		len++;
	}
	return (len);
}

void	ft_strlcat_c(char *dest, char src)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return ;
	str[0] = src;
	str[1] = '\0';
	ft_strlcat(dest, str, ft_strlen(dest) + ft_strlen(str) + 1);
	free(str);
}

void	ft_putnotag(char *s, t_tag *tag)
{	
	while (tag->start <= tag->i)
	{
		if (tag->pre == -1 && s[tag->start] == '.')
		{
			ft_putchar_len(s[tag->start], &tag->len);
			ft_putchar_len('0', &tag->len);
		}
		else
			ft_putchar_len(s[tag->start], &tag->len);
		tag->start++;
	}
}

int	ft_printf(const char *s, ...)
{
	t_tag	tag;

	tag.i = 0;
	tag.len = 0;
	va_start(tag.vaarg, s);
	while (s[tag.i])
	{
		if (s[tag.i] == '%' && s[tag.i + 1] != '\0')
		{
			ft_tags_init(&tag);
			ft_tags_def((char *) &s[0], &tag);
			ft_tags_insert((char *) &s[0], &tag);
		}
		else
			ft_putchar_len(s[tag.i], &(tag.len));
		if (s[tag.i])
			tag.i++;
	}
	va_end(tag.vaarg);
	return (tag.len);
}
