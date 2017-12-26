/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 01:03:20 by sergee            #+#    #+#             */
/*   Updated: 2017/12/25 23:16:16 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t symb;
t_flags g_flag = {{0}, 0, 0, {0}};
va_list	g_ap;
t_conver	g_conver[] = {
	/* %d */
	{"d", ft_nbr, ft_nbrlen, 7, NULL},
	{"hd", ft_nbr, ft_nbrlen, 6, NULL},
	{"hhd", ft_nbr, ft_nbrlen, 4, NULL},
	{"jd", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"zd", ft_lnbr, ft_lnbrlen, 10, NULL},
	{"ld", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"lld", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"D", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"hD", ft_nbr, ft_nbrlen, 7, NULL},
	{"hhD", ft_nbr, ft_nbrlen, 7, NULL},
	{"lD", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"llD", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"jD", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"zD", ft_lnbr, ft_lnbrlen, 10, NULL},
	/* %i */
	{"i", ft_nbr, ft_nbrlen, 7, NULL},
	{"hi", ft_nbr, ft_nbrlen, 6, NULL},
	{"hhi", ft_nbr, ft_nbrlen, 4, NULL},
	{"zi", ft_lnbr, ft_lnbrlen, 10, NULL},
	{"li", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"lli", ft_lnbr, ft_lnbrlen, 9, NULL},
	{"ji", ft_lnbr, ft_lnbrlen, 9, NULL},
	/* %o */
	{"o", ft_o_nbr, ft_o_nbrlen, 7, "0"},
	{"ho", ft_o_nbr, ft_o_nbrlen, 5, "0"},
	{"hho", ft_o_nbr, ft_o_nbrlen, 3, "0"},
	{"zo", ft_o_lnbr, ft_o_lnbrlen, 10, NULL},
	{"jo", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	{"lo", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	{"llo", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	{"O", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	{"zO", ft_o_lnbr, ft_o_lnbrlen, 10, NULL},
	{"hO", ft_o_nbr, ft_o_nbrlen, 5, "0X"},
	{"hhO", ft_o_nbr, ft_o_nbrlen, 5, "0X"},
	{"jO", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	{"lO", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	{"llO", ft_o_lnbr, ft_o_lnbrlen, 9, "0"},
	/* %s */
	{"s", ft_putnstr, ft_strnlen, 8, NULL},
	{"S", ft_putunstr, ft_strunlen, 8, NULL},
	{"hS", ft_putunstr, ft_strunlen, 8, NULL},
	{"hhS", ft_putunstr, ft_strunlen, 8, NULL},
	{"ls", ft_putunstr, ft_strunlen, 8, NULL},
	/* %x */
	{"x", ft_x_nbr, ft_x_nbrlen, 7, "0x"},
	{"zx", ft_x_lnbr, ft_x_lnbrlen, 10, NULL},
	{"hx", ft_x_nbr, ft_x_nbrlen, 5, "0x"},
	{"hhx", ft_x_nbr, ft_x_nbrlen, 3, "0x"},
	{"jx", ft_x_lnbr, ft_x_lnbrlen, 9, "0x"},
	{"lx", ft_x_lnbr, ft_x_lnbrlen, 9, "0x"},
	{"llx", ft_x_lnbr, ft_x_lnbrlen, 9, "0x"},
	{"X", ft_x_nbr, ft_x_nbrlen, 7, "0X"},
	{"zX", ft_x_lnbr, ft_x_lnbrlen, 10, NULL},
	{"hX", ft_x_nbr, ft_x_nbrlen, 5, "0X"},
	{"hhX", ft_x_nbr, ft_x_nbrlen, 3, "0X"},
	{"jX", ft_x_lnbr, ft_x_lnbrlen, 9, "0X"},
	{"lX", ft_x_lnbr, ft_x_lnbrlen, 9, "0X"},
	{"llX", ft_x_lnbr, ft_x_lnbrlen, 9, "0X"},
	/* %u */
	{"u", ft_unbr, ft_unbrlen, 7, NULL},
	{"zu", ft_ulnbr, ft_ulnbrlen, 10, NULL},
	{"hu", ft_unbr, ft_unbrlen, 5, NULL},
	{"hhu", ft_unbr, ft_unbrlen, 3, NULL},
	{"U", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"lU", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"llU", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"jU", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"zU", ft_ulnbr, ft_ulnbrlen, 10, NULL},
	{"hU", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"hhU", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"ju", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"lu", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	{"llu", ft_ulnbr, ft_ulnbrlen, 9, NULL},
	/* %c */
	{"c", ft_putchar, ft_ucharlen, 1, NULL},
	{"zc", ft_putchar, ft_ucharlen, 1, NULL},
	{"jc", ft_putchar, ft_ucharlen, 2, NULL},
	{"lc", ft_putchar, ft_ucharlen, 2, NULL},
	{"llc", ft_putchar, ft_ucharlen, 1, NULL},
	{"hc", ft_putchar, ft_ucharlen, 1, NULL},
	{"hhc", ft_putchar, ft_ucharlen, 1, NULL},
	{"C", ft_putchar, ft_ucharlen, 2, NULL},
	{"zC", ft_putchar, ft_ucharlen, 2, NULL},
	{"jC", ft_putchar, ft_ucharlen, 2, NULL},
	{"lC", ft_putchar, ft_ucharlen, 2, NULL},
	{"llC", ft_putchar, ft_ucharlen, 2, NULL},
	{"hC", ft_putchar, ft_ucharlen, 2, NULL},
	{"hhC", ft_putchar, ft_ucharlen, 2, NULL},
	/* %p */
	{"p", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	{"lp", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	{"llp", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	{"hp", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	{"hhp", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	{"zp", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	{"jp", ft_x_lnbr, ft_x_lnbrlen, 8, "0x"},
	/* %f */
	{"f", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"Lf", ft_fl_nbr, ft_fl_nbrlen, 14, NULL},
	{"lf", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"llf", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"hf", ft_f_nbr, ft_f_nbrlen, 13, NULL},
	{"hhf", ft_f_nbr, ft_f_nbrlen, 13, NULL},
	{"zf", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"jf", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"F", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"LF", ft_fl_nbr, ft_fl_nbrlen, 14, NULL},
	{"lF", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"llF", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"hF", ft_f_nbr, ft_f_nbrlen, 13, NULL},
	{"hhF", ft_f_nbr, ft_f_nbrlen, 13, NULL},
	{"jF", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	{"zF", ft_f_nbr, ft_f_nbrlen, 12, NULL},
	/* %e */
	{"e", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"Le", ft_el_nbr, ft_el_nbrlen, 14, NULL},
	{"le", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"lle", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"he", ft_e_nbr, ft_e_nbrlen, 13, NULL},
	{"hhe", ft_e_nbr, ft_e_nbrlen, 13, NULL},
	{"ze", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"je", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"E", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"LE", ft_el_nbr, ft_el_nbrlen, 14, NULL},
	{"lE", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"llE", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"hE", ft_e_nbr, ft_e_nbrlen, 13, NULL},
	{"hhE", ft_e_nbr, ft_e_nbrlen, 13, NULL},
	{"jE", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	{"zE", ft_e_nbr, ft_e_nbrlen, 12, NULL},
	/* %b */
	// {"b", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"lb", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"llb", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"hb", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"hhb", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"zb", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"jb", ft_putbinary, ft_nbrblen, 9, "0b", 1, 0},
	// {"B", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"lB", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"llB", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"hB", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"hhB", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"zB", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"jB", ft_putbinary, ft_nbrblen, 9, "0B", 1, 0},
	// {"r", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"lr", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"llr", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"hr", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"hhr", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"zr", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"jr", ft_putnnp_l, ft_strnnplen, 8, NULL, 1, 0},
	// {"R", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
	// {"lR", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
	// {"llR", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
	// {"hR", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
	// {"hhR", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
	// {"zR", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
	// {"jR", ft_putnnp_u, ft_strnnplen, 8, NULL, 1, 0},
};

void	set_types(t_conver *conv, t_basic *types)
{
	types->c = 0;
	conv->size == 1 ? types->c = (char)va_arg(g_ap, int) : 0;
	conv->size == 2 ? types->c = va_arg(g_ap, int) : 0;
	conv->size == 3 ? types->i = (t_uc)va_arg(g_ap, int) : 0;
	conv->size == 4 ? types->i = (char)va_arg(g_ap, int) : 0;
	conv->size == 5 ? types->i = (t_ush)va_arg(g_ap, int) : 0;
	conv->size == 6 ? types->i = (short)va_arg(g_ap, int) : 0;
	conv->size == 7 ? types->i = va_arg(g_ap, int) : 0;
	conv->size == 8 ? types->p = va_arg(g_ap, void *) : 0;
	conv->size == 9 ? types->im = va_arg(g_ap, intmax_t) : 0;
	conv->size == 10 ? types->im = va_arg(g_ap, size_t) : 0;
	conv->size == 11 ? types->pd = va_arg(g_ap, ptrdiff_t) : 0;
	conv->size == 12 ? types->f = va_arg(g_ap, double) : 0;
	conv->size == 13 ? types->f = (float)va_arg(g_ap, double) : 0;
	conv->size == 14 ? types->lf = va_arg(g_ap, t_ld) : 0;
}

void	ft_free(void)
{
	int i;

	i = 9;
	while (--i >= 0)
		g_flag.flags[i] = 0;
	g_flag.width = 0;
	g_flag.precision = 0;
	ft_bzero(g_flag.conversion, ft_strlen(g_flag.conversion));
	return ;
}

int		arg_zero(t_basic arg, t_conver c)
{
	if (c.size <= 2 && arg.c == 0)
		return (1);
	else if (c.size <= 7 && arg.i == 0)
		return (1);
	else if (c.size <= 7 && arg.i < 0)
		return (-1);
	else if (c.size <= 8 && arg.p == 0)
		return (1);
	else if (c.size <= 10 && arg.im == 0)
		return (1);
	else if (c.size < 10 && arg.im < 0)
		return (-1);
	else if (c.size <= 11 && arg.pd == 0)
		return (1);
	else if (c.size <= 13 && arg.f == 0)
		return (1);
	else if (c.size <= 13 && arg.f < 0)
		return (-1);
	else if (c.size <= 14 && arg.lf == 0)
		return (1);
	else if (c.size <= 14 && arg.lf < 0)
		return (-1);
	return (0);
}

size_t	ft_len_func(t_conver *c, t_basic types, size_t (*func)())
{
	if (c->size < 12)
		return (func(*(void **)&types));
	else if (c->size < 14)
		return (func(*(double *)&types, g_flag.precision));
	return (func(*(t_ld *)&types, g_flag.precision));
}

void	ft_wr_func(t_conver *c, t_basic types, void (*func)())
{
	if (c->size < 12)
		func((*(void **)&types), g_flag.precision);
	else if (c->size < 14)
		func((*(double *)&types), g_flag.precision);
	else
		func((*(t_ld *)&types), g_flag.precision);
	return ;
}
