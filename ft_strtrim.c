/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:28:53 by myevou            #+#    #+#             */
/*   Updated: 2023/09/19 17:08:02 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtrim(const char *s1, char const *set)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 1;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
}
