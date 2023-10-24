/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:42:55 by myevou            #+#    #+#             */
/*   Updated: 2023/10/24 18:02:43 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t sz)
// {
// 	size_t	i;
// 	size_t	dest_size;
// 	size_t	src_size;

// 	i = 0;
// 	dest_size = ft_strlen(dst);
// 	src_size = ft_strlen(src);
// 	if (dest_size >= size)
// 		return (src_size + size);
// 	while (src[i] != 0 && i < (size - dest_size - 1))
// 	{
// 		dest[dest_size + i] = src[i];
// 		i++;
// 	}
// 	dest[dest_size + i] = 0;
// 	return (src_size + dest_size);
// }

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(d);
	index = 0;
	while (d[index])
		index++;
	i = 0;
	while (s[i] && (i + index + 1) < (dstsize))
	{
		d[index + i] = s[i];
		i++;
	}
	if (i < dstsize)
		d[index + i] = '\0';
	if (dstsize <= dst_len)
		return (ft_strlen(s) + dstsize);
	else
		return (ft_strlen(s) + dst_len);
}
