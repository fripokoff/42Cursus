/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/12/29 15:56:48 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
	{
		new_str = (char *)malloc(sizeof(char));
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	while (s[start + i] && i < len)
		i++;
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
