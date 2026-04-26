/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseijas <sergioseijas.ferreiro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:18:53 by sseijas           #+#    #+#             */
/*   Updated: 2026/04/26 12:04:18 by sseijas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

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

int	is_rep(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str [i] == str[j])
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
	if (ft_strlen(base) < 2)
	{
		return (0);
	}
	if (is_rep(base) == 1)
	{
		return (0);
	}
	while (base[i] != '\0')
	{
		if (base[i] < 33 || base[i] > 126 || base[i] == 43 || base[i] == 45)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_put_base(long n, int len_base, char *base)
{
	if (n / len_base > 0)
	{
		ft_put_base(n / len_base, len_base, base);
	}
	write(1, &base[n % len_base], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		len_base;

	len_base = ft_strlen(base);
	if (base_check(base) == 0)
	{
		return ;
	}
	n = nbr;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	ft_put_base(n, len_base, base);
}

/*int main(void)
{
	char	*base = "01";
	int		nbr = -80000000;

	printf("Base válida = %d\n", base_check(base));
	ft_putnbr_base(nbr, base);
	return (0);
}*/
