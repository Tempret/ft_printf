/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:56:02 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 15:25:49 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_count = 0;

static void	print_result(char *str)
{
	ft_putstr(str);
	g_count += ft_strlen(str);
	free(str);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	char		*str;
	void		*ptr;
	t_form		curr_form;
	char		*dupl;

	dupl = (char *)format;
	va_start(ap, format);
	while (1)
	{
		if (!(parse_format(&dupl, &curr_form, &g_count)))
			break ;
		if (!is_another_char(curr_form.conv))
			ptr = va_arg(ap, void *);
		str = (!ptr && curr_form.conv == 's') ? ft_strdup("(null)") :
			data_to_str(&curr_form, ptr);
		strmodify(curr_form, &str);
		if (curr_form.null == -1 && curr_form.conv == 'c')
			continue ;
		else
			print_result(str);
	}
	va_end(ap);
	return (g_count);
}
