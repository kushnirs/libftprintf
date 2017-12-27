/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:57:24 by sergee            #+#    #+#             */
/*   Updated: 2017/12/27 11:16:24 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strpcmp(const char *s1, const char *s2)
{
	int	i;
	int	k;
	int	res;

	res = 0;
	i = -1;
	while (s2[++i])
	{
		k = -1;
		while (s1[++k])
			if (s2[i] == s1[k])
				res++;
	}
	return (res);
}
