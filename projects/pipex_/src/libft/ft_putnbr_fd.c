/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:03:57 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:40:41 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	div = n / 10;
	mod = n % 10;
	if (div)
		ft_putnbr_fd(div, fd);
	if (n < 0)
	{
		mod = -mod;
		if (!div)
			write(fd, "-", 1);
	}
	mod = mod + '0';
	write(fd, &mod, 1);
}
/*
** #include <unistd.h>
** 
** int main() {
**   ft_putnbr_fd(451485485,2);
**   return 0;
** }
*/