/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:11:11 by myevou            #+#    #+#             */
/*   Updated: 2023/10/29 17:36:28 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_len(int nbr)
// {
// 	int	len;

// 	len = 0;
// 	if (nbr <= 0)
// 		len = 1;
// 	while (nbr != 0)
// 	{
// 		nbr = nbr / 10;
// 		len++;
// 	}
// 	return (len);
// }

// static void	process(char *alpha, int len, unsigned int *nbr)
// {
// 	while (len >= 0)
// 	{
// 		alpha[len] = *nbr % 10 + '0';
// 		*nbr = *nbr / 10;
// 		len = len - 1;
// 	}
// }

// char	*ft_itoa(int n)
// {
// 	unsigned int	nbr;
// 	int				sign;
// 	int				len;
// 	char			*alpha;

// 	sign = 1;
// 	if (n < 0)
// 	{
// 		sign = -1;
// 		nbr = -n;
// 	}
// 	else
// 		nbr = n;
// 	len = ft_len(n) - 1;
// 	alpha = malloc(sizeof(char) * len + 2);
// 	if (!alpha)
// 		return (NULL);
// 	process(alpha, len, &nbr);
// 	if (sign == -1)
// 		alpha[0] = '-';
// 	return (alpha);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s \n", ft_itoa(321154));
// }

static	int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 && n > -2147483648)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				size;
	int				neg;
	unsigned int	tmp;

	size = ft_itoa_size(n);
	neg = (n < 0 ? 1 : 0);
	i = 1;
	if (!((str = (char *)malloc(sizeof(char) * ft_itoa_size(n) + 1))))
		return (NULL);
	tmp = (n < 0 ? -n : n);
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (neg)
		*str = '-';
	str[size] = '\0';
	return (str);
}
