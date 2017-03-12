/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:12:13 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 15:49:02 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_m(const char *str)
{
	int		i;
	int		negativ;
	int		number;

	if (!str++)
		return (0);
	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number) ? number : -1;
}

static void	fill_itoa_u(size_t nb, int base, int *i, char *str)
{
	char	*template;

	template = "0123456789abcdef";
	if (nb >= (size_t)base)
		fill_itoa_u(nb / base, base, i, str);
	str[(*i)++] = template[ft_abs(nb % base)];
}

char		*ft_itoa_base_u(size_t nb, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(64)))
		return (0);
	fill_itoa_u(nb, base, &i, str);
	str[i] = '\0';
	return (str);
}

static void	fill_itoa_s(ssize_t nb, int base, int *i, char *str)
{
	char	*template;

	template = "0123456789";
	if (nb >= base || nb <= -base)
		fill_itoa_s(nb / base, base, i, str);
	str[(*i)++] = template[ft_abs(nb % base)];
}

char		*ft_itoa_base_s(ssize_t nb, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(64)))
		return (0);
	if (nb < 0 && base == 10)
		str[i++] = '-';
	fill_itoa_s(nb, base, &i, str);
	str[i] = '\0';
	return (str);
}
