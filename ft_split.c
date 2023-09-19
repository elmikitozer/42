/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:52:23 by myevou            #+#    #+#             */
/*   Updated: 2023/09/19 17:04:45 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	freedfromdesire(char **split, int size)
{
	while (size-- >= 0)
		free(split[size]);
	free(split);
	return (-1);
}

static int	is_sep(char p, char c)
{
	if (p == c || p == 0)
		return (1);
	return (0);
}

static int	count_lines(char *str, char sep)
{
	int	i;
	int	lines;

	lines = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (char_is_separator(str[i + 1], sep) == 1
			&& char_is_separator(str[i], sep) == 0)
			lines++;
		i++;
	}
	return (lines);
}

static void	write_line(char *res, const char *s, char c)
{
	int	i;

	i = 0;
	while (is_sep(s[i], c))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
}

static int	write_split(char **split, const char *s, char c)
{
	int		i;
	int		j;
	int		line;

	line = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c) || !(s[i]))
			i++;
		else
		{
			j = 0;
			while ((s[i + j] != c) && (s[i + j]))
				j++;
			split[line] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split)
				return (freedfromdeesire(split, line - 1));
			write_line(split[line], s + i, c);
			i += j;
			line++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		lines;

	lines = count_lines(s, c);
	res = malloc(sizeof(char *) * (lines + 1));
	if (!res)
		return (NULL);
	res[lines] = 0;
	if (write_split(res, s, c) == -1)
		return (NULL);
	return (res);
}

// char	**ft_split(const char *s, char c)
// {
// 	char	**res;
// 	char	*tab;
// 	int		i;
// 	int		count;
// 	int		line;

// 	i = 0;
// 	count = 1;
// 	while (s[i])
// 	{
// 		if (s[i++] == c)
// 			count++;
// 	}
// 	res = malloc(sizeof(char *) * (count + 1));
// 	if (!res)
// 		return (NULL);
// 	while (s)
// 	{
// 		count = 0;
// 		while (s[i++] != c)
// 			count++;
// 		tab = malloc(sizeof(char) * count + 1);
// 		if (!tab)
// 		{
// 			while (line >= 0)
// 				free(res[line]);
// 			free(res);
// 		}
// 		while (*s != c)
// 			*(tab++) = *(s++);
// 		*tab = 0;
// 		res[line] = tab;
// 		s++;
// 	}
// 	return (res);
// }
