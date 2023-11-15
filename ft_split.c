/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:52:23 by myevou            #+#    #+#             */
/*   Updated: 2023/11/10 20:52:12 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	freedfromdesire(char **split, int size)
// {
// 	while (size-- >= 0)
// 		free(split[size]);
// 	free(split);
// 	return (-1);
// }

// // static int	is_sep(char p, char c)
// // {
// // 	if (p == c || p == 0)
// // 		return (1);
// // 	return (0);
// // }

// static int	count_lines(const char *str, char sep)
// {
// 	int	i;
// 	int	lines;

// 	lines = 0;
// 	i = 0;
// 	while (str[i] != 0)
// 	{
// 		if (((str[i + 1] == sep) || str[i + 1])
// 			&& (str[i] != sep && str[i] != 0))
// 			lines++;
// 		i++;
// 	}
// 	return (lines);
// }

// static void	write_line(char *res, const char *s, char c)
// {
// 	int	i;

// 	i = 0;
// 	while ((s[i] == c) || s[i])
// 	{
// 		res[i] = s[i];
// 		i++;
// 	}
// 	res[i] = 0;
// }

// static int	write_split(char **split, const char *s, char c)
// {
// 	int		i;
// 	int		j;
// 	int		line;

// 	line = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if ((s[i] == c) || !(s[i]))
// 			i++;
// 		else
// 		{
// 			j = 0;
// 			while ((s[i + j] != c) && (s[i + j]))
// 				j++;
// 			split[line] = (char *)malloc(sizeof(char) * (j + 1));
// 			if (!split)
// 				return (freedfromdesire(split, line - 1));
// 			write_line(split[line], s + i, c);
// 			i += j;
// 			line++;
// 		}
// 	}
// 	return (0);
// }

// char	**ft_split(const char *s, char c)
// {
// 	char	**res;
// 	int		lines;

// 	lines = count_lines(s, c);
// 	res = malloc(sizeof(char *) * (lines + 1));
// 	if (!res)
// 		return (NULL);
// 	res[lines] = 0;
// 	if (write_split(res, s, c) == -1)
// 		return (NULL);
// 	return (res);
// }

// // char	**ft_split(const char *s, char c)
// // {
// // 	char	**res;
// // 	char	*tab;
// // 	int		i;
// // 	int		count;
// // 	int		line;

// // 	i = 0;
// // 	count = 1;
// // 	while (s[i])
// // 	{
// // 		if (s[i++] == c)
// // 			count++;
// // 	}
// // 	res = malloc(sizeof(char *) * (count + 1));
// // 	if (!res)
// // 		return (NULL);
// // 	while (s)
// // 	{
// // 		count = 0;
// // 		while (s[i++] != c)
// // 			count++;
// // 		tab = malloc(sizeof(char) * count + 1);
// // 		if (!tab)
// // 		{
// // 			while (line >= 0)
// // 				free(res[line]);
// // 			free(res);
// // 		}
// // 		while (*s != c)
// // 			*(tab++) = *(s++);
// // 		*tab = 0;
// // 		res[line] = tab;
// // 		s++;
// // 	}
// // 	return (res);
// // }
static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

static void	set_mem(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		count = 0;
		while (s[index + count] && s[index + count] != c)
			count++;
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return ;
			fill_tab(tab[i], (s + index), c);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	set_mem(tab, s, c);
	return (tab);
}
