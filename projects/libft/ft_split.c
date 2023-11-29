/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:44:49 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:47:35 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	trig;
	int	i;

	trig = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && trig == 0)
		{
			trig = 1;
			i++;
		}
		else if (*s == c && trig != 0)
		{
			trig = 0;
		}
		s++;
	}
	return (i);
}

static char	*ft_get_word(const char *s, int start, int finish)
{
	char	*split;
	int		i;
	int		end;

	end = finish - start;
	split = malloc(sizeof(char) * (end + 1));
	i = 0;
	while (i < end)
		split[i++] = s[start++];
	split[i] = 0;
	return (split);
}

static char	**ft_protect(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		word_start;
	char	**split;

	split = ft_protect(s, c);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	word_start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start < 0)
			word_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start >= 0)
		{
			split[j++] = ft_get_word(s, word_start, i);
			word_start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
** #include <stdio.h>
** #include <stdlib.h>
** #include <string.h>
** 
** size_t	ft_strlen(const char *c)
** {
** 	size_t	i;
** 
** 	i = 0;
** 	while (c[i])
** 		i++;
** 	return (i);
** }
** 
** int	main(void)
** {
** 	char	*str;
** 	char	**split_str;
** 
** 	str = "";
** 	split_str = ft_split(str, ' ');
** 	printf("La chaîne de caractères est vide : %s\n",
** 		split_str == NULL ? "oui" : "non");
** 	str = "Bonjour, monde !";
** 	split_str = ft_split(str, ' ');
** 	printf("La chaîne de caractères ne contient qu'un seul mot : %s\n",
** 		split_str != NULL ? "oui" : "non");
** 	printf("Le mot est : %s\n", split_str[0]);
** 	str = "Bonjour, monde ! C'estf un beau jour.";
** 	split_str = ft_split(str, ' ');
** 	printf("La chaîne de caractères contient plusieurs mots : %s\n",
** 		split_str != NULL ? "oui" : "non");
** 	printf("Le premier mot est : %s\n", split_str[0]);
** 	printf("Le deuxième mot est : %s\n", split_str[1]);
** 	str = "Bonjour, monde !";
** 	split_str = ft_split(str, '\0');
** 	printf("Le délimiteur est nul : %s\n", split_str == NULL ? "oui" : "non");
** 	str = "Bonjour, monde !";
** 	split_str = ft_split(str, '!');
** 	printf("Le délimiteur n'est pas présent dans la chaîne de caractères :
** 		%s\n", split_str != NULL ? "oui" : "non");
** 	printf("Le mot est : %s\n", split_str[0]);
** 	return (0);
** }
*/