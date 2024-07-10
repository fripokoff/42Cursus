/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdtag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 05:05:58 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:41:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_insert2(t_tag *tag, char *c, size_t *nbsize)
{
	if (*c == '0' && tag->pre == 0)
	{
		*c = '\0';
		*nbsize = 0;
	}
	if (tag->pre != -1 || (*c == '0' && tag->pre == 0))
		tag->zero = ' ';
}

static void	ft_insert(t_tag *tag, char *s, size_t nbsize)
{
	size_t	i;

	ft_insert2(tag, &(s[0]), &nbsize);
	if (tag->plus || tag->space)
		nbsize++;
	if (nbsize < (size_t) tag->wi && !tag->minus && tag->zero == ' ')
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
	if (tag->plus && s[0] != '-')
		ft_putchar_len('+', &tag->len);
	if (s[0] == '-')
		ft_putchar_len('-', &tag->len);
	if (nbsize < (size_t) tag->wi && !tag->minus && tag->zero == '0')
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
	if (tag->space && s[0] != '-')
		ft_putchar_len(' ', &tag->len);
	if ((size_t) tag->pre > ft_strlen(s) - (s[0] == '-') && tag->pre != -1)
		ft_putcharnb_len('0', tag->pre - ft_strlen(s) + (s[0] == '-'),
			&tag->len);
	i = -1;
	while (s[++i])
		if (s[i] != '-')
			ft_putchar_len(s[i], &tag->len);
	if (nbsize < (size_t) tag->wi && tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
}

void	ft_putdtag(t_tag *tag)
{
	char	*str;

	str = ft_itoa(va_arg(tag->vaarg, int));
	if (tag->pre != -1 && (size_t) tag->pre > ft_strlen(str) - (str[0] == '-'))
	{
		ft_insert(tag, str, tag->pre + (str[0] == '-'));
	}
	else
		ft_insert(tag, str, ft_strlen(str));
	free(str);
}
