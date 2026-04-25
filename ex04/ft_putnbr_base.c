/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseijas <sergioseijas.ferreiro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:12:07 by sseijas           #+#    #+#             */
/*   Updated: 2026/04/25 19:57:36 by sseijas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_repe(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	base_check(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) >= 2)
	{
		if (is_repe(base) == 1)
		{
			return (0);
		}
		while (base[i] != '\0')
		{
			if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			{
				return (0);
			}
			if (base[i] <= 32 || base[i] > 126)
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			len_base;

	len_base = ft_strlen(base);
	if (base_check(base) == 0)
	{
		return ;
	}
	if (nbr < 0)
	{
		n = -nbr;
		write(1, "-", 1);
	}
	n = nbr;
	if (n / len_base != 0)
	{
		ft_putnbr_base(n / len_base, base);
	}
	write(1, &base[n % len_base], 1);
}

/*int	main(void)
{
	char	*base = "0";
	int		nbr = 76584;

	ft_putnbr_base(nbr, base);
	return (0);
}*/
