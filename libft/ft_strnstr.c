/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:09:58 by myevou            #+#    #+#             */
/*   Updated: 2023/09/11 19:27:08 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_found(const char *str, const char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	if (!to_find[0])
		return (str);
	while (*str && len)
	{
		if (str[0] == to_find[0] && is_found(str, to_find) != 0)
			return (str);
		str++;
		len--;
	}
	return (0);
}
