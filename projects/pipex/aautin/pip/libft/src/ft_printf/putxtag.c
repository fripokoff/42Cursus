/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putxtag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:04:42 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:41:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_puthexa_len(unsigned int nb, int *len, int maj, char *str)
{
	char	*hexabase;

	if (maj)
		hexabase = "0123456789ABCDEF";
	else
		hexabase = "0123456789abcdef";
	if (nb < 16)
		ft_strlcat_c(str, hexabase[nb]);
	else
	{
		ft_puthexa_len(nb / 16, len, maj, str);
		ft_strlcat_c(str, hexabase[nb % 16]);
	}
}

static void	ft_insert0x(int maj, int *len)
{
	if (maj)
		ft_putstr_len("0X", len);
	else
		ft_putstr_len("0x", len);
}

static void	ft_insertxtag(t_tag *tag, char *s, size_t nbsize, int maj)
{
	int	i;

	if (s[0] == '0' && tag->pre == 0)
	{
		s[0] = '\0';
		nbsize = 0;
	}
	if (tag->pre != -1)
		tag->zero = ' ';
	if (tag->hastag && tag->wi < 0)
		tag->wi = 0;
	if (tag->hastag && tag->wi < 0)
		tag->wi -= 2;
	if ((size_t) tag->wi > nbsize && !tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
	if (tag->hastag)
		ft_insert0x(maj, &tag->len);
	if (nbsize > ft_strlen(s) && tag->pre != -1)
		ft_putcharnb_len('0', nbsize - ft_strlen(s), &tag->len);
	i = -1;
	while (s[++i])
		ft_putchar_len(s[i], &tag->len);
	if (nbsize < (size_t) tag->wi && tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - nbsize, &tag->len);
}

void	ft_putxtag(t_tag *tag, int maj)
{
	char	*str;
	int		nb;

	nb = va_arg(tag->vaarg, unsigned int);
	if (tag->hastag)
		tag->hastag -= (nb == 0);
	str = (char *)malloc((ft_nblen(nb, 16) + 1) * sizeof(char));
	if (!str)
		return ;
	str[0] = '\0';
	ft_puthexa_len(nb, &tag->len, maj, str);
	if (tag->pre != -1)
	{
		tag->zero = ' ';
		if ((size_t) tag->pre > ft_strlen(str))
			ft_insertxtag(tag, str, tag->pre, maj);
		else
			ft_insertxtag(tag, str, ft_strlen(str), maj);
	}
	else
		ft_insertxtag(tag, str, ft_strlen(str), maj);
	free(str);
}
