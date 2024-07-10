/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:06 by aautin            #+#    #+#             */
/*   Updated: 2023/11/27 16:40:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nb_size(int n)
{
	int		i;
	int		temp;

	i = 1;
	temp = n / 10;
	while (temp)
	{
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;
	int		sign;

	if (n == -2147483648 || n == -2147483648L || n == -2147483648LL)
		return (ft_strdup("-2147483648\0"));
	i = ft_nb_size(n);
	array = (char *)malloc((i + 1) * sizeof(char));
	if (!array)
		return (NULL);
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	array[i] = '\0';
	while (i--)
	{
		array[i] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		array[0] = '-';
	return (array);
}

// int main()
// {
// 	char *str;
// 	str = ft_itoa(-2147483648LL);
// 	printf("%s", str);
// 	free(str);
// 	str = ft_itoa(-2147483648L);
// 	printf("%s", str);
// 	free(str);
// 	str = ft_itoa(-2147483648);
// 	printf("%s", str);
// 	free(str);
// }