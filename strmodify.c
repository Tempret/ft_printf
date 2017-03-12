/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmodify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:10:53 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 16:27:07 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_modify(t_form curr, char **str, int *len)
{
	if (ft_strchr(*str, '-') && curr.precis >= curr.width)
		curr.min++;
	if (curr.padding)
		make_padding(str, curr.padding + curr.min, *len, curr.flag);
	if (curr.precis && curr.width > curr.precis && curr.precis != -1)
		make_fix_precis(*str, curr.width - curr.precis, curr.precis, len);
	if (curr.minus && curr.padding + curr.min > curr.precis &&
		curr.precis < curr.width)
		make_reverse(*str);
	if (curr.zero && !curr.minus && !curr.precis)
		make_zero(*str);
	if ((curr.plus || curr.space) && (curr.conv == 'd' || curr.conv == 'i'))
		make_aerial(str, curr, *len);
	if ((curr.hash && (curr.conv == 'o' || curr.conv == 'O' ||
		curr.conv == 'x' || curr.conv == 'X')) || (curr.conv == 'p'))
		make_hash(str, curr.conv, curr);
	if (curr.hash && curr.width && *len < curr.width &&
		(*len = ft_strlen(*str)) > curr.width)
		(*str)[curr.width] = '\0';
}

static void	do_string_modif(t_form curr, char **str, int len)
{
	if ((curr.precis && curr.precis < len) || curr.precis == -1)
		make_precis_s(str, curr);
	if ((size_t)curr.width > ft_strlen(*str))
		make_width_s(str, curr);
}

int			strmodify(t_form curr, char **str)
{
	int		len;

	len = ft_strlen(*str);
	if (curr.null == -1 && curr.conv == 'c')
	{
		fix_null_char(curr);
		return (1);
	}
	if (curr.precis == -1 && **str == '0' && curr.width &&
		(!(curr.conv == 'o' || curr.conv == 'O') || !curr.hash))
		**str = ' ';
	else if (curr.precis == -1 && **str == '0' &&
		!(curr.conv == 'o' || curr.conv == 'O'))
		**str = '\0';
	if (curr.precis == -1 && (curr.conv == 'o' || curr.conv == 'O') &&
		!curr.hash && !curr.width)
		**str = '\0';
	if (curr.conv == 's' || curr.conv == 'S' || curr.conv == 'c')
	{
		do_string_modif(curr, str, len);
		return (1);
	}
	do_modify(curr, str, &len);
	return (1);
}
