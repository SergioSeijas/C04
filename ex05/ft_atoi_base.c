/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseijas <sergioseijas.ferreiro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:16:26 by sseijas           #+#    #+#             */
/*   Updated: 2026/04/26 16:16:28 by sseijas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (base_check(base) == 0)
		return (0);
	while (*str == 32 || (*str <= 13 && *str >= 9))
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == '-')
		{
			sign = sign * (-1);
		}
		str++;
	}
	while (get_val(*str, base) != -1)
	{
		res = res * ft_strlen(base) + get_val(*str, base);
		str++;
	}
	return (res * sign);
}

/*int main(void)
{
	char	*base = "0123456789abcdef";
	char	*str = "   -+-+++ff45pmikjpm";
	printf("ff45 en decimal: %d\n", ft_atoi_base(str, base));
	return (0);
}*/
