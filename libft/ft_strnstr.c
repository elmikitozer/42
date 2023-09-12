/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikayay <mikayay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:09:58 by myevou            #+#    #+#             */
/*   Updated: 2023/09/12 13:05:31 by mikayay          ###   ########.fr       */
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
	if (!s2[0])
		return (s1);
	while (*s1 && len)
	{
		if (s1[0] == s2[0] && is_found(s1, s2) != 0)
			return (s1);
		s1++;
		len--;
	}
	return (0);
}
