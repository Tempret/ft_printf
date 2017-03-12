/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:29:56 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 14:28:01 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conv_letter(char letter)
{
	if (letter == 's' || letter == 'S' || letter == 'p' || letter == 'd' ||
			letter == 'D' || letter == 'i' || letter == 'o' || letter == 'O' ||
			letter == 'u' || letter == 'U' || letter == 'x' || letter == 'X' ||
			letter == 'c' || letter == 'C')
		return (1);
	else
		return (0);
}

int		is_another_char(char l)
{
	if (l == 33 || l == 37 || l == 38 || l == 40 || l == 41 || l == 47 ||
			l == 60 || l == 61 || l == 62 || l == 63 || l == 64 || l == 'B' ||
			l == 'H' || l == 'I' || l == 'J' || l == 'K' || l == 'M' ||
			l == 'N' || l == 'P' || l == 'Q' || l == 'R' || l == 'T' ||
			l == 'V' || l == 'W' || l == 'Y' || l == 'Z' || l == 91 ||
			l == 93 || l == 94 || l == 'b' || l == 'k' || l == 'm' ||
			l == 'r' || l == 'w' || l == 'y' || l == 123 || l == 124 ||
			l == 125 || l == 126)
		return (1);
	else
		return (0);
}

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}
