/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:11:57 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/25 12:31:43 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	int i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] && n-- > 0)
	{
		ft_putchar(s[i]);
		i++;
	}
	return ;
}

void	ft_putunstr(int const *s, size_t n)
{
	intmax_t	j;

	if (!s)
		return (ft_putstr("(null)"));
	j = ft_strulen(s);
	(intmax_t)n < j ? j = n : 0;
	while (*s && (j -= ft_ucharlen(*s)) >= 0)
		ft_putchar(*s++);
	return ;
}
