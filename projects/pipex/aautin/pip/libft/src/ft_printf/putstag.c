/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:00:15 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:41:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_putnullstr(int *printed, t_tag *tag)
{
	int	len;

	len = 6;
	if (tag->pre < len && tag->pre > -1)
		len = tag->pre;
	if (tag->wi > len && !tag->minus)
		ft_putcharnb_len(' ', tag->wi - len, &tag->len);
	if (!(tag->pre < 6) || tag->pre == -1)
		ft_putstr_len("(null)", printed);
	if (tag->wi > len && tag->minus)
		ft_putcharnb_len(' ', tag->wi - len, &tag->len);
}

void	ft_putstr_len(char *str, int *printed)
{
	int	i;

	if (!str)
		ft_putstr_len("(null)", printed);
	else
	{
		i = 0;
		while (str[i])
		{
			ft_putchar_len(str[i], printed);
			i++;
		}
	}
}

void	ft_putstag(t_tag *tag)
{
	char	*str;
	int		len;
	int		i;

	i = -1;
	str = va_arg(tag->vaarg, char *);
	if (!str)
		return (ft_putnullstr(&tag->len, tag));
	len = ft_strlen(str);
	if (tag->pre < len && tag->pre > -1)
		len = tag->pre;
	if (tag->wi > len && !tag->minus)
		ft_putcharnb_len(' ', tag->wi - len, &tag->len);
	while (++i < len && tag->pre != -2 && str)
		ft_putchar_len(str[i], &tag->len);
	if (tag->wi > len && tag->minus)
		ft_putcharnb_len(' ', tag->wi - len, &tag->len);
}
