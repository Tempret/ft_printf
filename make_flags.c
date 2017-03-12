/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:28:37 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/11 18:15:58 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		make_reverse(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == ' ' && !(str[i] == '-'))
		i++;
	ft_memmove(str, str + i, len - i);
	i = len - i;
	while (str[i])
		str[i++] = ' ';
}

void		make_zero(char *string)
{
	int		minus;
	int		len;

	len = ft_strlen(string);
	minus = 0;
	while (*string)
	{
		if (*string == '-')
			minus++;
		if (*string == ' ' || *string == '-')
			*string = '0';
		string++;
	}
	if (minus)
		*(string - len) = '-';
}

static void	make_else_hash(char **str, int space, int zero)
{
	char	*new;

	if (space == 0 && zero < 1)
	{
		new = ft_strjoin("0", *str);
		free(*str);
		*str = new;
	}
	else
		(*str)[space - 1] = '0';
}

static void	make_x_hash(char **str, int space, int zero, char conv)
{
	char	*new;

	if ((space == 0 || space == 1) && zero < 2)
	{
		if (conv == 'x')
			new = ft_strjoin("0x", *str + space);
		else
			new = ft_strjoin("0X", *str + space);
		free(*str);
		*str = new;
	}
	else
	{
		if (space < zero)
			space = 2;
		(*str)[space - 2] = '0';
		(*str)[space - 1] = conv;
	}
}

void		make_hash(char **str, char conv, t_form curr)
{
	int		space;
	int		zero;

	if (curr.null == -1)
		return ;
	space = 0;
	zero = 0;
	if (conv == 'p')
		conv = 'x';
	while ((*str)[space] == ' ')
		space++;
	while ((*str)[zero] == '0')
		zero++;
	if (conv == 'x' || conv == 'X')
		make_x_hash(str, space, zero, conv);
	else
		make_else_hash(str, space, zero);
}
