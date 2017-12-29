/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:54:22 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/20 17:46:25 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	//printf("%d\n", printf("%lc\n", 120));
	ft_printf("|%.Lf|", 256.456);
	printf("\n-------------------------\n");
	printf("|%.Lf|", 256.54);
	// printf("my: %d\n", ft_printf("%lu", -42L));
	// printf("or: %d\n", printf("%lu", -42L));
	//printf("%d\n", printf("or: %.1s\n", "423.23423"));
	//printf("%d\n", ft_printf("my: %.1s\n", "423.23423"));
	//ft_printf("or:  %#x  ", 0);
	// printf("%d\n", printf("or: %#09x\n", 0));
	// printf("%d\n", ft_printf("my: %#09x\n", 0));
	//printf("%d\n", ft_printf("my: %#5x\n", 0));
	return (0);
}