/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_aerial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:17:28 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/11 18:26:10 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_aerial_l(char **str, int src_len, char aerial)
{
	char	*new;

	if (!(new = ft_strnew(src_len + 1)))
		return ;
	new[0] = aerial;
	ft_memmove(new + 1, *str, src_len);
	free(*str);
	*str = new;
}

void		make_aerial(char **str, t_form curr, int len_g)
{
	int		src_len;
	int		i;
	char	aerial;

	aerial = (curr.space && !curr.plus) ? ' ' : '+';
	if (ft_strchr(*str, '-'))
		return ;
	src_len = ft_strlen(*str);
	i = 0;
	if ((curr.precis && !curr.width) || len_g == src_len ||
			(curr.width < curr.precis))
		make_aerial_l(str, src_len, aerial);
	else
	{
		if (ft_isdigit(**str) && ft_strchr(*str, ' '))
			ft_memmove(*str + 1, *str, len_g);
		else
			while ((*str)[i] == ' ')
				i++;
		i = !i ? 0 : i - 1;
		(*str)[i] = aerial;
	}
}
