/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:37:12 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 13:43:20 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*destination, const void	*source, size_t num )
{
	const char	*s;
	char		*d;

	if (destination == source)
		return (destination);
	s = (const char *)source;
	d = (char *)destination;
	if (d < s)
	{
		while (num--)
			d[num] = s[num];
		return (destination);
	}
	while (num--)
		*d++ = *s++;
	return (destination);
}


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
