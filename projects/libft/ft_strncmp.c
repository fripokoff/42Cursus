/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:37:57 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 12:21:12 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
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
