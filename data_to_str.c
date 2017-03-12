/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:38:43 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 16:30:21 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fix_alphabet(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

static int	set_base(char c)
{
	if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else
		return (10);
}

static void	do_dec_str(t_form *curr, char **str, void *data)
{
	if (ft_strstr(curr->fmt_block, "l") || ft_strstr(curr->fmt_block, "j") ||
			ft_strstr(curr->fmt_block, "z") || curr->c == 'D')
		*str = ft_itoa_base_s((long)data, 10);
	else if (ft_strstr(curr->fmt_block, "hh"))
		*str = ft_itoa_base_s((signed char)data, 10);
	else if (ft_strstr(curr->fmt_block, "h"))
		*str = ft_itoa_base_s((short)data, 10);
	else if (ft_strstr(curr->fmt_block, "ll"))
		*str = ft_itoa_base_s((long long)data, 10);
	else
		*str = ft_itoa_base_s((int)data, 10);
}

static void	do_hex_octa_str(t_form *curr, char **str, int base, void *data)
{
	if (ft_strstr(curr->fmt_block, "l") || curr->c == 'O' ||
		curr->c == 'U' || curr->c == 'p')
		*str = ft_itoa_base_u((unsigned long)data, base);
	else if (ft_strstr(curr->fmt_block, "h"))
		*str = ft_itoa_base_u((unsigned short)data, base);
	else if (ft_strstr(curr->fmt_block, "hh"))
		*str = ft_itoa_base_u((unsigned char)data, base);
	else if (ft_strstr(curr->fmt_block, "ll") ||
			ft_strstr(curr->fmt_block, "j") || ft_strstr(curr->fmt_block, "z"))
		*str = ft_itoa_base_u((unsigned long long)data, base);
	else
		*str = ft_itoa_base_u((unsigned int)data, base);
	if (curr->c == 'X')
		fix_alphabet(*str);
}

char		*data_to_str(t_form *f, void *data)
{
	char	*str;
	int		base;

	base = set_base(f->c);
	if (f->c == 'd' || f->c == 'i' || f->c == 'D')
		do_dec_str(f, &str, data);
	else if (f->c == 'o' || f->c == 'O' || f->c == 'u' || f->c == 'U' ||
			f->c == 'x' || f->c == 'X' || f->c == 'p')
		do_hex_octa_str(f, &str, base, data);
	else if (f->c == 's' || f->c == 'S')
		str = ft_strdup((char *)data);
	else if (f->c == 'c' || f->c == 'C')
	{
		str = ft_strnew(1);
		str[0] = (char)data;
	}
	else
	{
		str = ft_strnew(1);
		str[0] = f->c;
	}
	f->null = ((*str == '0' && f->c != 'p') ||
			(((char)data == '\0') && (f->c == 'c' || f->c == 'C'))) ? -1 : 0;
	return (str);
}
