/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:13:04 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:49:48 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main() {
  char str[15] = "Hello, world!";

  printf("Avant bzero(): %s\n", str);
  ft_bzero(str, sizeof(str));
  printf("Après bzero(): %s\n", str);

  return 0;
}
*/