/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:32:34 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/11 17:53:03 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_padding(char **str, int padding, int len, char flag)
{
	char	*new;
	int		i;
	int		minus;

	minus = 0;
	i = 0;
	if (!(new = ft_strnew(padding)))
		return ;
	if (ft_strchr(*str, '-') && flag == '0')
	{
		new[i++] = '-';
		len--;
		minus++;
	}
	while (i < padding - len)
		new[i++] = flag;
	ft_memcpy(new + i, *str + minus, len);
	free(*str);
	*str = new;
}

void	make_width_s(char **str, t_form curr)
{
	char	*new;
	int		len;
	int		i;
	char	flag;

	len = ft_strlen(*str);
	i = curr.width - len;
	new = ft_strnew(curr.width);
	flag = (curr.zero && (curr.conv == 's' ||
		curr.conv == 'c') && !curr.minus) ? '0' : ' ';
	while (i)
		new[--i] = flag;
	ft_memmove(new + curr.width - len, *str, len);
	free(*str);
	*str = new;
	if (curr.minus)
	{
		ft_memmove(new, new + curr.width - len, len);
		new += len;
		while (*new)
			*new++ = flag;
	}
}

void	make_precis_s(char **str, t_form curr)
{
	char	*new;

	if (curr.precis == -1)
		curr.precis = 0;
	new = ft_strnew(curr.precis);
	ft_memmove(new, *str, curr.precis);
	*str = new;
}

void	make_fix_precis(char *src, int len_fix, int precis, int *len_g)
{
	int		i;

	i = len_fix;
	if (ft_strchr(src, '-') && len_fix <= precis)
		src[i - 1] = '-';
	while (!ft_isdigit(src[i]))
		src[i++] = '0';
	*len_g = precis;
}

void	fix_null_char(t_form curr)
{
	if (curr.width && !curr.minus)
	{
		g_count += curr.width;
		while (--curr.width)
			write(1, " ", 1);
		write(1, "\0", 1);
	}
	else if (curr.width && curr.minus)
	{
		g_count += curr.width;
		write(1, "\0", 1);
		while (--curr.width)
			write(1, " ", 1);
	}
	else
	{
		write(1, "\0", 1);
		g_count++;
	}
}
