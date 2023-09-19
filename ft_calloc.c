/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:24:01 by myevou            #+#    #+#             */
/*   Updated: 2023/09/19 13:28:46 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	size_t	total;
	char	*mem;

	total = size * count;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < total)
		mem[i++] = 0;
	return (mem);
}
