/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:37:57 by kpires            #+#    #+#             */
/*   Updated: 2023/11/23 12:12:48 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
  const char *s1 = "Hello, c";
  const char *s2 = "Hello, c";

  int r = strncmp(s1, s2, 20);

  if (r == 0) {
    printf("Les deux chaînes sont égales.\n");
  } else if (r > 0) {
    printf("La chaîne s1 '%s' est supérieure à la chaîne '%s'.\n", s1, s2);
  } else { 
    printf("La chaîne s1'%s' est inférieure à la chaîne '%s'.\n", s1, s2);
  }

  return 0;
}
*/