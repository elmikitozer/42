/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:11:11 by myevou            #+#    #+#             */
/*   Updated: 2023/09/22 18:15:18 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void	process(char *alpha, int *len, int *nbr)
{
	while (len >= 0)
	{
		alpha[*len] = *nbr % 10 + '0';
		*nbr = *nbr / 10;
		*len = *len - 1;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*alpha;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nbr = -n;
	}
	else
		nbr = n;
	len = ft_len(n);
	alpha = malloc(sizeof(char) * len + 1);
	if (!alpha)
		return (NULL);
	process(alpha, &len, &nbr);
	if (sign == -1)
		alpha[0];
	return (alpha);
}
