/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:07:58 by myevou            #+#    #+#             */
/*   Updated: 2023/11/07 18:38:12 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == c)
// 		return ((char *)(s + i));
// }

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
