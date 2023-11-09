/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:32:43 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:22:07 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)

{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = (unsigned char)c;
	return (s);
}

/*
int main()
{
  char str[10];

  // Remplit la chaîne avec le caractère 'a'.
  ft_memset(str, 127, sizeof(str));

  // Imprime la chaîne.
  printf("%s\n", str);

  return 0;
}int main()
{
  char str[10];

  // Remplit la chaîne avec le caractère 'a'.
  ft_memset(str, 127, sizeof(str));

  // Imprime la chaîne.
  printf("%s\n", str);

  return 0;
}
*/