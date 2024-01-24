/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:01:49 by kpires            #+#    #+#             */
/*   Updated: 2024/01/24 12:53:26 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*c;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
