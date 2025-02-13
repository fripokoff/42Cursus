/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:19:35 by kpires            #+#    #+#             */
/*   Updated: 2024/12/23 22:46:54 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i != n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	if (!n)
		return (srclen);
	destlen = ft_strnlen(dest, n);
	if (destlen == n)
		return (n + srclen);
	if (srclen < n - destlen)
		ft_memcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + destlen, src, n - destlen - 1);
		dest[n - 1] = '\0';
	}
	return (srclen + destlen);
}
