/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:11:24 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/12 15:51:42 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int         g_count;

typedef struct 	s_format
{
	char		plus;
	char		minus;
	char		zero;
	char		hash;
	char		space;
	int			width;
	int			precis;
	char		*fmt_block;
	char		conv;
    int         null;
    int         padding;
    char        flag;
    int         min;
    char        c;
}				t_form;

int             ft_printf(const char *fmt, ...);
int				is_conv_letter(char letter);
int				is_another_char(char letter);
int             is_size_modif(char l);
char			*ft_l_strchr(char *str, char goal);
char			*find_width_ptr(char *str);
int             ft_abs(int nb);
int             ft_atoi_m(const char *str);
int             find_zero(const char *str);
char            *data_to_str(t_form *curr, void *data);
char 	        *ft_itoa_base_u(size_t nb, int base);
char 	        *ft_itoa_base_s(ssize_t nb, int base);
int              strmodify(t_form curr, char **str);

/*MAKE_PADDING.C*/
void			make_padding(char **str, int padding, int len, char flag);
void			make_width_s(char **str, t_form curr);
void			make_precis_s(char **str, t_form curr);
void			make_fix_precis(char *src, int len_fix, int precis, int *len_g);
void   			fix_null_char(t_form curr);

/*MAKE_FLAGS.C*/
void			make_reverse(char *str);
void			make_zero(char *string);
void			make_hash(char **str, char conv, t_form curr);

/*MAKE_AERIAL.C*/
void			make_aerial(char **str, t_form curr, int len_g);

/*DATA_TO_STR.C*/
char            *data_to_str(t_form *curr, void *data);

/*PARSE_FORMAT.C*/
int				parse_format(char **fmt, t_form *curr_form, int *count);

#endif
