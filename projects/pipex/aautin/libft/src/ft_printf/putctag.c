/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putctag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:42:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:41:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putchar_len(int a, int *len)
{
	ft_putchar_fd(a, 1);
	*len += 1;
}

void	ft_putcharnb_len(char a, int nb, int *len)
{
	while (nb--)
		ft_putchar_len(a, len);
}

void	ft_putctag(t_tag *tag)
{
	if (tag->wi > 1 && !tag->minus)
		ft_putcharnb_len(' ', tag->wi - 1, &tag->len);
	ft_putchar_len(va_arg(tag->vaarg, int), &tag->len);
	if (tag->wi > 1 && tag->minus)
		ft_putcharnb_len(' ', tag->wi - 1, &tag->len);
}
