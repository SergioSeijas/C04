/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseijas <sergioseijas.ferreiro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:31:52 by sseijas           #+#    #+#             */
/*   Updated: 2026/04/25 18:08:54 by sseijas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		i++;
	}
	return (i);
}

int	convert_to_int(char *str, int n)
{
	int	result;
	int	i;

	i = 1;
	result = str[0] - 48;
	while (i < n)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	count;
	int	positive;
	int	i;

	i = 0;
	positive = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			count = ft_count(&str[i]);
			return (convert_to_int(&str[i], count) * positive);
		}
		if (str[i] == 45)
		{
			positive = positive * (-1);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*str = "    ---+--+1234567";

	printf("%d\n", ft_atoi(str));
	return (0);
}*/
