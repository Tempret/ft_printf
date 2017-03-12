/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:22:14 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 15:28:38 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_size_modif(char l)
{
	if (l == 'l' || l == 'h' || l == 'z' || l == 'j')
		return (1);
	else
		return (0);
}

char	*ft_l_strchr(char *str, char goal)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	while (tmp != str || (tmp == str && *tmp == goal))
	{
		if (*tmp == goal)
			return (tmp);
		tmp--;
	}
	return (NULL);
}

char	*find_width_ptr(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	while (!(ft_isdigit(*tmp)) && tmp != str)
		tmp--;
	while (((ft_isdigit(*tmp) || (*tmp == '.')) && tmp != str))
	{
		if (*tmp == '.')
		{
			while (!(ft_isdigit(*tmp)) && tmp != str)
				tmp--;
			tmp++;
		}
		tmp--;
	}
	if (*tmp == '#')
		tmp++;
	return (tmp);
}

int		find_zero(const char *str)
{
	char	*finder;

	if (*str == '0')
		return (1);
	finder = (char *)str;
	while (*finder)
	{
		if (*finder == '0' && !ft_isdigit(*(finder - 1)))
			return (1);
		finder++;
	}
	return (0);
}
