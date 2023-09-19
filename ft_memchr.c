/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:04:48 by myevou            #+#    #+#             */
/*   Updated: 2023/09/19 13:13:02 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cs;

	ptr = (unsigned char *) s;
	cs = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == cs)
			return (ptr + i);
		i++;
	}
	return (0);
}
