/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:28:53 by myevou            #+#    #+#             */
/*   Updated: 2023/09/22 17:03:22 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	ischar(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*trim_end(const char *s1, const char *set, size_t *j, size_t i)
{
	size_t	j;
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	j = 0;
	while (ischar(*(s1 + len - j - 1), set))
		j++;
	if ((dst = ft_calloc(sizeof(char), len - (j + i) + 1)) == NULL)
		return (NULL);
	while (*j < len - (j + i))
	{
		*(dst + *j) = *(s1 + i + *j);
		*j += 1;
	}
	return (dst);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	count = 1;
	while (ischar(s1[i]), set)
		i++;
	j = 0;
	if (i == len)
		dest = malloc(1);
	else
		dest = trim_end(s1, set, &j, i);
	if (dest)
		*(dst[j]) = 0;

}
