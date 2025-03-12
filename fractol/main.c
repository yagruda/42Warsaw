/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:21:23 by yhruda            #+#    #+#             */
/*   Updated: 2025/03/12 19:06:33 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "printf/ft_printf.h"
#include <stdio.h>

int ft_summ(int a, int b);

int main()
{
	char *str = "Hello World!";
	printf("%s\n", str);
	printf("%d\n", ft_summ(5, 3));
	return 0;
}