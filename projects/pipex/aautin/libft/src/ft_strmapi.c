/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// char	incrementation(unsigned int n, char c)
// {
// 	if (n % 2)
// 		return (c + 1);
// 	else
// 		return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	newstr = (char *)malloc((ft_strlen((char *) s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, (char *) s, ft_strlen((char *) s) + 1);
	i = 0;
	while (newstr[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
