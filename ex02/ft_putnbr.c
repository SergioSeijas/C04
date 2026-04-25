/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseijas <sergioseijas.ferreiro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:07:36 by sseijas           #+#    #+#             */
/*   Updated: 2026/04/25 17:28:58 by sseijas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_positive_integer(int nb)
{
	int		i;
	int		count;
	char	aux[1000];

	i = 0;
	count = 0;
	while (nb > 9)
	{
		aux[count] = nb % 10 + 48;
		nb = nb / 10;
		count++;
	}
	aux[count] = nb + 48;
	count++;
	while (i < count)
	{
		write(1, &aux[count - i - 1], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	ft_print_positive_integer(nb);
}

/*int	main(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = -2147483648;
	n2 = 0;
	n3 = 2147483647;
	ft_putnbr(n1);
	write(1, "\n", 1);
	ft_putnbr(n2);
	write(1, "\n", 1);
	ft_putnbr(n3);
	write(1, "\n", 1);
	return (0);
}*/
