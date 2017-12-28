/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:59:10 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/28 11:12:23 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nonconv(char *str)
{
	if (g_f.flags[4])
		while (--g_f.w > g_f.p)
			ft_putchar('0');
	if (g_f.flags[0])
	{
		ft_putchar(*str);
		while (--g_f.w > 0)
			ft_putchar(' ');
		return (1);
	}
	while (--g_f.w > 0)
		ft_putchar(' ');
	ft_putchar(*str);
	return (1);
}

static void	ft_output(t_conver *c, t_basic *types)
{
	if (ft_strpcmp(c->conv, "Ssc") && g_f.flags[4])
		while (g_f.w-- > g_f.p)
			ft_putchar('0');
	if (!g_f.flags[0])
		while (g_f.w-- > g_f.p)
			ft_putchar(' ');
	if (g_f.flags[1] && ft_strpcmp(c->conv, "dDi")
		&& arg_zero(types, c) >= 0)
		ft_putchar('+');
	if ((g_f.flags[3] && (c->size <= 7 || c->size >= 9)
		&& arg_zero(types, c) <= 0) || c->size == 8)
		ft_putstr(c->prefix);
	ft_wr_func(c, *types, c->wrfunc);
	if (g_f.flags[0])
		while (g_f.w-- > g_f.p)
			ft_putchar(' ');
	return ;
}

static void	ft_apply_nbr2(t_conver *c, t_basic *types)
{
	if (g_f.flags[3] || c->size == 8)
	{
		if (g_f.flags[4] && !g_f.p && !arg_zero(types, c))
			g_f.p = g_f.w - ft_strlen(c->prefix);
		g_f.w > (int)ft_strlen(c->prefix) ? g_f.w -= ft_strlen(c->prefix) : 0;
		if (ft_strpcmp(c->conv, "oO") && g_f.p > (int)ft_strlen(c->prefix))
			g_f.p -= ft_strlen(c->prefix);
		g_f.flags[4] ? g_f.p = g_f.w : 0;
	}
	if (g_f.flags[2] && ft_strpcmp(c->conv, "dDi") &&
		!g_f.flags[1] && arg_zero(types, c) >= 0)
	{
		ft_putchar(' ');
		g_f.w--;
	}
	if (arg_zero(types, c) == -1 &&
		g_f.p >= (int)ft_len_func(c, *types, c->lenf))
		g_f.p++;
	if (g_f.flags[4] && !g_f.flags[0] && (c->size <= 7 ||
		c->size >= 12 || c->size == 9))
		!g_f.p ? g_f.p = g_f.w : 0;
	if (g_f.p < (int)ft_len_func(c, *types, c->lenf) && c->size < 12)
		g_f.p = ft_len_func(c, *types, c->lenf);
	return ;
}

static void	ft_apply_nbr(t_conver *c, t_basic *types)
{
	g_f.p < 0 ? g_f.p = 0 : 0;
	(arg_zero(types, c) == 1 && (ft_strpcmp(c->conv, "cC")))
		? g_f.p = 1 : 0;
	if (((!ft_strpcmp(c->conv, "oO"))) || !g_f.flags[3])
		if (arg_zero(types, c) == 1 && g_f.flags[8] && !g_f.p)
		{
			c->size == 8 ? ft_putstr(c->prefix) : 0;
			while (g_f.w--)
				ft_putchar(' ');
			return ;
		}
	(g_f.flags[1] && arg_zero(types, c) != -1) ? g_f.w-- : 0;
	if (!g_f.flags[8])
	{
		c->size >= 12 ? g_f.p = 6 : 0;
		c->size == 8 ? g_f.p = ft_len_func(c, *types, c->lenf) : 0;
	}
	ft_apply_nbr2(c, types);
	ft_output(c, types);
	return ;
}

void		ft_apply_flags(va_list *ap)
{
	size_t		i;
	t_basic		types;
	t_conver	c;

	i = 0;
	while (ft_strcmp(g_c[i].conv, g_f.conversion))
		i++;
	c = g_c[i];
	set_types(&c, &types, ap);
	g_f.flags[0] ? g_f.flags[4] = 0 : 0;
	if (ft_strpcmp(c.conv, "sS"))
	{
		i = ft_len_func(&c, types, c.lenf);
		if (g_f.flags[8] && !g_f.p)
			i = 0;
		(g_f.p <= 0 || !i || g_f.p > (int)i) ? g_f.p = i : 0;
		if (ft_strchr(c.conv, 'S') &&
			g_f.p > (int)(i = ft_strunlen(*(void **)&types, g_f.p)))
			g_f.p = i;
		arg_zero(&types, &c) == 1 && !g_f.p ? types.p = "\0" : 0;
		ft_output(&c, &types);
	}
	else
		ft_apply_nbr(&c, &types);
	return ;
}
