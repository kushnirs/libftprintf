/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergee <sergee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:54:22 by skushnir          #+#    #+#             */
/*   Updated: 2017/12/25 23:53:35 by sergee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <locale.h>
#include "printf/ft_printf.h"



int main(void)
{
	setlocale (LC_ALL, "");
	//printf("%d\n", printf("%lc\n", 120));
	// printf("\nmy: %d\n", ft_printf("%05d", -42));
	// printf("\nor: %d\n", printf("%05d", -42));
	//printf("%d\n", printf("or: %.1s\n", "423.23423"));
	//printf("%d\n", ft_printf("my: %.1s\n", "423.23423"));
	//ft_printf("or:  %#x  ", 0);
	// printf("%d\n", printf("or: %#09x\n", 0));
	// printf("%d\n", ft_printf("my: %#09x\n", 0));
	//printf("%d\n", ft_printf("my: %#5x\n", 0));

// 	printf("\nmy: %d\n", ft_printf("%c", 'c'));
// 	printf("\nmy: %d\n", ft_printf("%c%c", '4', '2'));
// 	printf("\nmy: %d\n", ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'));
// 	printf("\nmy: %d\n", ft_printf("%c", 0));
	//printf("\nor: %d\n", printf("{%f}{%F}", 1.42, 1.42));
// ft_printf("%*d", 5, 42);
// ft_printf("{%*d}", -5, 42);
// ft_printf("{%*d}", 0, 42);
// ft_printf("{%*c}", 0, 0);
// ft_printf("{%*c}", -15, 0);
// ft_printf("{%.*d}", 5, 42);
// ft_printf("{%.*d}", -5, 42);
// ft_printf("{%.*d}", 0, 42);
// ft_printf("{%.*s}", 5, "42");
// ft_printf("{%.*s}", -5, "42");
// ft_printf("{%.*s}", 0, "42");
// ft_printf("{%*s}", 5, 0);
//ft_printf("%+c", 0);
// ft_printf("%+c", 0);
// ft_printf("%+C", 0);
// ft_printf("%+o", 0);
// ft_printf("%+o", 42);
double jopa = 2.147484e+09;
printf("%d\n", ft_printf("%e", jopa));
// printf("%d\n", ft_printf("{%05s}", "abc"));
// ft_printf("%+O", 42);
// ft_printf("[%+s]", 0);
// ft_printf("[%+s]", "(null)");
// ft_printf("%+O", 1);
printf("\n---------------\n\n");
// printf("%+c", 0);
// printf("%+C", 0);
// printf("%+o", 0);
// printf("%+o", 42);
printf("%d\n", printf("%e", jopa));
// printf("%d\n", printf("{%05s}", "abc"));
// printf("%+O", 42);
// printf("[%+s]", 0);
// printf("[%+s]", "(null)");
// printf("%+O", 1);
	return (0);
}