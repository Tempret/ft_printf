/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:30:25 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 14:50:42 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	form_obj_init(char *f_block, t_form *c_frm)
{
	c_frm->plus = (ft_strchr(f_block, '+')) ? 1 : 0;
	c_frm->minus = (ft_strchr(f_block, '-')) ? 1 : 0;
	c_frm->zero = find_zero(f_block);
	c_frm->hash = (ft_strchr(f_block, '#')) ? 1 : 0;
	c_frm->space = (ft_strchr(f_block, ' ')) ? 1 : 0;
	c_frm->width = ft_abs(ft_atoi(find_width_ptr(f_block)));
	c_frm->precis = ft_atoi_m(ft_l_strchr(f_block, '.'));
	c_frm->fmt_block = f_block;
	c_frm->conv = f_block[ft_strlen(f_block) - 1];
	c_frm->min = 0;
	c_frm->padding = (c_frm->precis > c_frm->width) ? c_frm->precis :
		c_frm->width;
	c_frm->flag = (c_frm->precis >= c_frm->width) ? '0' : ' ';
	c_frm->c = c_frm->fmt_block[ft_strlen(c_frm->fmt_block) - 1];
}

static int	do_parse(char **fmt, t_form *curr)
{
	char	*block;
	char	*tmp;

	block = *fmt + 1;
	if (!*block)
		return (0);
	while (!(is_conv_letter(*block)) && !(is_another_char(*block)))
	{
		if (!*block && is_size_modif(*(block - 1)))
			return (0);
		block++;
	}
	tmp = block;
	block = ft_strsub(*fmt, 1, block - *fmt);
	*fmt = ++tmp;
	form_obj_init(block, curr);
	return (1);
}

int			parse_format(char **fmt, t_form *curr_form, int *count)
{
	while (**fmt)
	{
		if (**fmt == '%' && *(*fmt + 1) != '%')
			return (do_parse(fmt, curr_form)) ? 1 : 0;
		else if (**fmt == '%' && *(*fmt + 1) == '%')
		{
			write(1, "%", 1);
			(*fmt)++;
			(*count)++;
		}
		else
		{
			write(1, *fmt, 1);
			(*count)++;
		}
		(*fmt)++;
	}
	return (0);
}
