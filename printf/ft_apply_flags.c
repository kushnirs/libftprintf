/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:59:10 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/25 16:06:18 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_percent(void)
{
	if (g_flag.flags[0])
	{
		ft_putchar('%');
		while (--g_flag.width > 0)
			ft_putchar(' ');
		return;
	}
	while (--g_flag.width > 0)
			ft_putchar(' ');
	ft_putchar('%');
	return;
}

static void	ft_write(t_conver c, t_basic types)
{
	// printf("/width= %d/\n", g_flag.width);
	// printf("/prec= %d/\n", g_flag.precision);
	// printf("len= %zu\n", ft_len_func(&c, types, c.lenfunc));
	if ((ft_strchr(c.conv, 'S') || ft_strchr(c.conv, 's')
		|| ft_strchr(c.conv, 'c')) && g_flag.flags[4])
		while (g_flag.width-- > ft_len_func(&c, types, c.lenfunc))
			ft_putchar('0');
	if (!g_flag.flags[0])
		while (g_flag.width-- > g_flag.precision)
			ft_putchar(' ');
	if (g_flag.flags[1] && (ft_strchr(c.conv, 'd') || ft_strchr(c.conv, 'i') ||
		ft_strchr(c.conv, 'D') || ft_strchr(c.conv, 'I'))
		&& arg_zero(types, c) >= 0)
		ft_putchar('+');
	if ((g_flag.flags[3] && ((c.size >= 3 && c.size <= 7) || c.size >= 12 ||
	c.size == 9) && arg_zero(types, c) <= 0) || c.size == 8)
		ft_putstr(c.prefix);
	ft_wr_func(&c, types, c.wrfunc);
	if (g_flag.flags[0])
			while (g_flag.width-- > g_flag.precision)
				ft_putchar(' ');
	return;
}

static void	ft_apply_nbr(t_conver c, t_basic types)
{
	if (!ft_strchr(c.conv, 'o') || !g_flag.flags[3])
		if (arg_zero(types, c) == 1 && g_flag.flags[8] && !g_flag.precision)
		{
			c.size == 8 ? ft_putstr(c.prefix) : 0;
			while (g_flag.width--)
					ft_putchar(' ');
			return;
		}
	if (g_flag.flags[1] && arg_zero(types, c) != -1)
		g_flag.width--;
	if (!g_flag.flags[8])
		{
			c.size >= 12 ? g_flag.precision = 6 : 0;
			c.size == 8 ? g_flag.precision = ft_len_func(&c, types, c.lenfunc) : 0;
		}
	if (g_flag.flags[3] || c.size == 8)
	{
		if (g_flag.flags[4] && !g_flag.precision && !arg_zero(types, c))
			g_flag.precision = g_flag.width - ft_strlen(c.prefix);
		g_flag.width > ft_strlen(c.prefix) ? g_flag.width -= ft_strlen(c.prefix) : 0;
		g_flag.flags[4] ? g_flag.precision = g_flag.width : 0;
	}
	if (g_flag.flags[2] && (ft_strchr(c.conv, 'd') || ft_strchr(c.conv, 'i') ||
		ft_strchr(c.conv, 'D') || ft_strchr(c.conv, 'I')) && !g_flag.flags[1] && !arg_zero(types, c))
	{	
		ft_putchar(' ');
		g_flag.width--;
	}
	if (arg_zero(types, c) == -1 && g_flag.precision >= ft_len_func(&c, types, c.lenfunc))
		g_flag.precision++;
	if (g_flag.flags[4] && !g_flag.flags[0] && (c.size <= 7 || c.size >= 12 || c.size == 9))
		!g_flag.precision ? g_flag.precision = g_flag.width : 0;
	if (g_flag.precision < ft_len_func(&c, types, c.lenfunc))
		g_flag.precision = ft_len_func(&c, types, c.lenfunc);
	ft_write(c, types);
	return;
}

void	ft_apply_flags(void)
{
	int			i;
	t_basic		types;
	t_conver	c;

	if (!ft_strcmp("%", g_flag.conversion))
		return (ft_percent());
	i = 0;
	while (ft_strcmp(g_conver[i].conv, g_flag.conversion))
		i++;
	c = g_conver[i];
	set_types(&c, &types);
	g_flag.flags[0] ? g_flag.flags[4] = 0 : 0;
	if ((ft_strchr(c.conv, 'S') || ft_strchr(c.conv, 's')))
	{
		i = ft_len_func(&c, types, c.lenfunc);
		if (!g_flag.precision || !i)
			g_flag.precision = i;
		g_flag.width < (i - g_flag.precision) ?
		g_flag.width = i - g_flag.precision : 0;
		ft_write(c, types);
	}
	else
		ft_apply_nbr(c, types);
	return;
}
