/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// la fonction avec laquelle comparer ft_strnstr
// char	*ft2_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t h;
// 	size_t n;

// 	h = 0;
// 	if (needle[0] == '\0')
// 		return ((char *)haystack);
// 	while (haystack[h] != '\0')
// 	{
// 		n = 0;
// 		while (haystack[h + n] == needle[n] && (h + n) < len)
// 		{
// 			if (haystack[h + n] == '\0' && needle[n] == '\0')
// 				return ((char *)&haystack[h]);
// 			n++;
// 		}
// 		if (needle[n] == '\0')
// 			return ((char *)haystack + h);
// 		h++;
// 	}
// 	return (0);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *) &haystack[0]);
	if (!len)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] == haystack[i + j] && (i + j) < len)
			j++;
		if (!needle[j])
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}
