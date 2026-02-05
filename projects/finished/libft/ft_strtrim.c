/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:27:01 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 18:07:23 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int s, char const *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_check(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (ft_check(s1[len - 1], set))
		len--;
	len = len - i;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, &s1[i], len);
	str[len] = '\0';
	return (str);
}
/*
** #include <stdio.h>
** #include <stdlib.h>
** 
** void	*ft_memcpy(void	*destination, const void	*source, size_t num )
** {
** 	char		*d;
** 	const char	*s;
** 
** 	if (destination == source || num == 0)
** 		return (destination);
** 	if (!destination && !source)
** 		return (0);
** 	s = (const char *)source;
** 	d = (char *)destination;
** 	while (num--)
** 		d[num] = s[num];
** 	return (destination);
** }
** char	*ft_strdup(const char *s)
** {
** 	char			*c;
** 	unsigned int	len;
** 	unsigned int	i;
** 
** 	i = 0;
** 	len = ft_strlen(s);
** 	c = (char *)malloc(sizeof(char) * len + 1);
** 	if (!c)
** 		return (NULL);
** 	while (i < len)
** 	{
** 		c[i] = s[i];
** 		i++;
** 	}
** 	c[i] = '\0';
** 	return (c);
** }
** size_t	ft_strlen(const char *c)
** {
** 	size_t	i;
** 
** 	i = 0;
** 	while (c[i])
** 		i++;
** 	return (i);
** }
**  int	main(int ac, char** av)
** {
** 	(void)ac;
** 	printf("%s\n" , ft_strtrim(av[1],av[2]));
** 	return (0);
** }
*/
