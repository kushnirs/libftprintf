/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:47:07 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/25 15:26:16 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_nbr(int n, int i)
{
	int		a;
	int		c;
	long	b;

	b = n;
	if (n < 0)
	{
		b = -b;
		ft_putchar('-');
	}
	while (i-- > ft_nbrlen(n))
		ft_putchar('0');
	a = 1;
	while ((b / a) >= 10)
		a = a * 10;
	while (a > 0)
	{
		c = b / a;
		b = b - c * a;
		c = c + 48;
		a = a / 10;
		ft_putchar(c);
	}
}

void			ft_lnbr(intmax_t n, int i)
{
	long		a;
	int			c;
	uintmax_t	b;

	b = n;
	if (n < 0)
	{
		b = -b;
		ft_putchar('-');
	}
	while (i-- > ft_lnbrlen(n))
		ft_putchar('0');
	a = 1;
	while ((b / a) >= 10)
		a = a * 10;
	while (a > 0)
	{
		c = b / a;
		b = b - c * a;
		c = c + 48;
		a = a / 10;
		ft_putchar(c);
	}
}

void			ft_unbr(t_ui n, int i)
{
	long		a;
	int			c;
	unsigned int	b;

	while (i-- > ft_unbrlen(n))
		ft_putchar('0');
	b = n;
	a = 1;
	while ((b / a) >= 10)
		a = a * 10;
	while (a > 0)
	{
		c = b / a;
		b = b - c * a;
		c = c + 48;
		a = a / 10;
		ft_putchar(c);
	}
}

void			ft_ulnbr(uintmax_t n, int i)
{
	t_ul		a;
	long		c;
	uintmax_t	b;

	b = n;
	while (i-- > ft_ulnbrlen(n))
		ft_putchar('0');
	a = 1;
	while ((b / a) >= 10)
		a = a * 10;
	while (a > 0)
	{
		c = b / a;
		b = b - c * a;
		c = c + 48;
		a = a / 10;
		ft_putchar(c);
	}
}

size_t	ft_nbrlen(int nbr)
{
	int	i;
	unsigned long	nb;

	i = 1;
	nb = nbr;
	if (nbr < 0)
		nb = -nb;
	nbr < 0 ? i++ : 0;
	while((nb = nb / 10) >= 1)
		i++;
	return (i);
}

size_t	ft_unbrlen(t_ui nbr)
{
	long	i;

	i = 1;
	while((nbr = nbr / 10) >= 1)
		i++;
	return (i);
}

size_t	ft_lnbrlen(long nbr)
{
	int	i;
	unsigned long	nb;

	i = 1;
	nb = nbr;
	if (nbr < 0)
		nb = -nb;
	nbr < 0 ? i++ : 0;
	while((nb = nb / 10) >= 1)
		i++;
	return (i);
}

size_t	ft_ulnbrlen(t_ul nbr)
{
	int		i;
	t_ul	nb;

	i = 1;
	nb = nbr;
	while((nb = nb / 10) >= 1)
		i++;
	return (i);
}
