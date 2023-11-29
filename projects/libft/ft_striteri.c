/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:53:03 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:59:30 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
** #include <stdio.h>
** #include <string.h>
** 
**  void afficher_caractere(unsigned int i, char *c) {
**     printf("[%d] = %c\n", i, *c);
**   }
** 
** int main() {
**   char str[] = "Bonjour, monde !";
**   ft_striteri(str, afficher_caractere);
**   printf("\n");
**   return 0;
** }
*/