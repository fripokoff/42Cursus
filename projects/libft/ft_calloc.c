/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:24:41 by kpires            #+#    #+#             */
/*   Updated: 2023/11/27 17:28:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t nmemb, size_t size )
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	if (nmemb && size && nmemb > 2147483647 / size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*
#include "stdio.h"
int	main(){
	ft_calloc(0,1);
	return 0;
}*/