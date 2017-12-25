/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublenbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 03:20:28 by sergee            #+#    #+#             */
/*   Updated: 2017/12/18 02:17:45 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_f_nbr(double n, int i)
{
	double	fraction;

	if (n != n || n == INF)
	{
		if (!ft_strcmp("lf", g_flag.conversion) ||
			!ft_strcmp("f", g_flag.conversion))
			n == INF ? ft_putstr("inf") : ft_putstr("nan");
		else
			n == INF ? ft_putstr("INF") : ft_putstr("NAN");
		return;
	}
	ft_lnbr((long)n, 0);
	i != 0 ? ft_putchar('.') : 0;
	if (n < 0)
		n = -n;
	fraction = n - (long)n;
	while (i-- > 0)
	{
		ft_unbr((fraction *= 10), 0); 
		fraction -= (long)fraction;
	}
}

void	ft_fl_nbr(t_ld n, int i)
{
	t_ld	fraction;

	if (n != n || n == INF)
	{
		if (!ft_strcmp("lf", g_flag.conversion) ||
			!ft_strcmp("f", g_flag.conversion))
			n == INF ? ft_putstr("inf") : ft_putstr("nan");
		else
			n == INF ? ft_putstr("INF") : ft_putstr("NAN");
		return;
	}
	ft_nbr((long)n, 0);
	i != 0 ? ft_putchar('.') : 0;
	if (n < 0)
		n = -n;
	fraction = n - (long)n;
	while (i-- > 0)
	{
		ft_unbr((fraction *= 10), 0); 
		fraction -= (long)fraction;
	}
}

size_t	ft_f_nbrlen(double n, int i)
{
	size_t len;

	if (n != n || n == INF)
		return (3);
	len = ft_lnbrlen((t_ul)n) + i + 1;
	return (len);
}

size_t	ft_fl_nbrlen(t_ld n, int i)
{
	size_t len;

	if (n != n || n == INF)
		return (3);
	len = ft_ulnbrlen((t_ui)n) + i + 1;
	return (len);
}