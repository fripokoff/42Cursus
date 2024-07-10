/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:53:50 by aautin            #+#    #+#             */
/*   Updated: 2023/12/29 15:58:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putphexa_len(size_t nb, int *len, int maj, char *str)
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
		ft_putphexa_len(nb / 16, len, maj, str);
		ft_strlcat_c(str, hexabase[nb % 16]);
	}
}

void	ft_insertptag(t_tag *tag, int len, char *str)
{
	int	nb;

	tag->wi -= 2;
	if (tag->pre < len && tag->pre != -1)
		len = tag->pre;
	if (tag->minus)
		ft_putstr_len("0x", &tag->len);
	if (tag->wi > len && !tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - len, &tag->len);
	if (!tag->minus)
		ft_putstr_len("0x", &tag->len);
	nb = -1;
	while (++nb < len)
		ft_putchar_len(str[nb], &tag->len);
	if (tag->wi > len && tag->minus)
		ft_putcharnb_len(tag->zero, tag->wi - len, &tag->len);
}

void	ft_putptag(t_tag *tag)
{
	char		*str;
	size_t		nb;

	nb = va_arg(tag->vaarg, size_t);
	if (nb == 0)
	{
		nb = 5;
		if ((size_t) tag->wi > nb && !tag->minus)
			ft_putcharnb_len(tag->zero, tag->wi - nb, &tag->len);
		ft_putstr_len("(nil)", &tag->len);
		if ((size_t) tag->wi > nb && tag->minus)
			ft_putcharnb_len(tag->zero, tag->wi - nb, &tag->len);
	}
	else
	{
		str = (char *)malloc((ft_nblen(nb, 16) + 1) * sizeof(char));
		if (!str)
			return ;
		str[0] = '\0';
		ft_putphexa_len(nb, &tag->len, 0, str);
		ft_insertptag(tag, ft_strlen(str), str);
		free(str);
	}
}
