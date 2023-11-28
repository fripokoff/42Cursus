/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fripok <fripok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:37:12 by kpires            #+#    #+#             */
/*   Updated: 2023/11/28 17:27:31 by fripok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*destination, const void	*source, size_t num )
{
	char	*s;
	char	*d;
	size_t	i;

	if (!destination && !source)
		return (NULL);
	s = (char *)source;
	d = (char *)destination;
	i = 0;
	if (d > s)
		while (num-- > 0)
			d[num] = s[num];
	else
	{
		while (i < num)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (destination);
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
	int	s1 = 10;
	int s2 = 15;
	int	oct = 1;
  char str[] = "memmove can be very useful......";
   char str2[] = "memmove can be very useful......";
  memmove (str+s1,str+s2,oct);
  ft_memmove (str2+s1,str2+s2,oct);
  puts ("memoove :");
  puts (str);
  puts ("ft_memoove :");
  puts (str2);
  return 0;
}
*/