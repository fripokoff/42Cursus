/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:35:19 by kpires            #+#    #+#             */
/*   Updated: 2025/01/06 14:41:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	size = (unsigned int)ft_strlen(s + start);
	if (len < size)
		size = len;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < size)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
