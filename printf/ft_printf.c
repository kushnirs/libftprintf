/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:25:16 by sergee            #+#    #+#             */
/*   Updated: 2017/12/25 23:21:45 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_conversion(char *str)
{
	int i;

	i = -1;
	while(str[++i])
	{
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z'
			|| str[i] == 'L')
			g_flag.conversion[i] = str[i];
		else if (str[i] == 'd' || str[i] == 'c' || str[i] == 'u' || str[i] == 'X'
			|| str[i] == 'x' || str[i] == 'b' || str[i] == 'e' || str[i] == 'E' ||
			str[i] == 'f' || str[i] == 'g' || str[i] == 'G' || str[i] == 'S' ||
			str[i] == 's' || str[i] == 'p' || str[i] == 'o' || str[i] == '%' ||
			str[i] == 'U' || str[i] == 'i' || str[i] == 'D' || str[i] == 'O' ||
			str[i] == 'C')
		{
			g_flag.conversion[i] = str[i];
			g_flag.conversion[i + 1] = 0;
			break;
		}
	}
	if (!g_flag.conversion[0])
		return (0);
	ft_apply_flags();
	return (i + 1);
}

static int	ft_width(char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
		g_flag.width = va_arg(g_ap, int);
	else
	{
		g_flag.width = 0;
		while (str[i] >= '0' && str[i] <= '9')
			g_flag.width = g_flag.width * 10 + (str[i++] - 48);
		i--;
	}
	if (g_flag.width < 0)
	{
		g_flag.width = -g_flag.width;
		g_flag.flags[0] = 1;
	}
	// printf("/width= %d/\n", g_flag.width);
	return (i);
}

static int	ft_precision(char *str)
{
	int i;

	g_flag.flags[8] = 1;
	i = 0;
	if (str[i] == '.' && str[i + 1] == '*')
		g_flag.precision = va_arg(g_ap, int);
	else if (str[i] == '.' && str[i + 1] > '0' && str[i + 1] <= '9' && ++i)
		while (str[i] >= '0' && str[i] <= '9')
			g_flag.precision = g_flag.precision * 10 + (str[i++] - 48);
	return (i);
}

static int	ft_read_flags(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		str[i] == '-' ? g_flag.flags[0] = 1 : 0;
		str[i] == '+' ? g_flag.flags[1] = 1 : 0;
		str[i] == ' ' ? g_flag.flags[2] = 1 : 0;
		str[i] == '#' ? g_flag.flags[3] = 1 : 0;
		str[i] == '0' ? g_flag.flags[4] = 1 : 0;
		str[i] == '$' ? g_flag.flags[5] = 1 : 0;
		str[i] == 'L' ? g_flag.flags[6] = 1 : 0;
		str[i] == '\'' ? g_flag.flags[7] = 1 : 0;
		str[i] == '.' ?	g_flag.flags[8] = 1 : 0;
		if ((str[i] == '*' && str[i - 1] != '.') ||
			(str[i] > '0' && str[i] <= '9' && str[i - 1] != '.'))
			i += ft_width(&str[i]);
		if (str[i] == '.')
			i += ft_precision(&str[i]);
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| str[i] == '%')
			break;
	}
	//str[i] == 0 ? i-- : 0;
	// for (int k = 0; k < 9; k++)
	// 	printf("/flags= %d/\n", g_flag.flags[k]);
	return (i + ft_find_conversion(&str[i]));
}

int	ft_printf(const char *format, ...)
{
	char	*str;

	symb = 0;
	str = (char*)format;
	va_start(g_ap, format);
	while (*str)
	{
		if (*str == '%')
		{
			str += ft_read_flags(str + 1);
			ft_free();
		}
		else if (*str != '%')
			ft_putchar(*str);
		// if (!*str)
		// 	return (symb);
		str++;
	}
	return (symb);
}
