/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:16:59 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/23 14:40:41 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// if we have not digit - return 0
// return 1 if all inputs are valid

static int	check_initial_input(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Error: number of philosophers must be greater than 0\n");
		return (0);
	}
	return (1);
}

static int	validate_all_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error: all arguments must be positive integers\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_valid_input(int argc, char **argv)
{
	if (!check_initial_input(argc, argv))
		return (0);
	if (!validate_all_digits(argv))
		return (0);
	if (ft_atoi(argv[1]) > 250)
	{
		printf("Error: max number of philosophers is 250\n");
		return (0);
	}
	return (1);
}

// TBD, it's basic version
// ad a check case for max number of philos - 250
int	input_check(int argc, char **argv)
{
	int	n_philos;

	n_philos = 0;
	if (!check_valid_input(argc, argv))
		return (0);
	n_philos = ft_atoi(argv[1]);
	return (n_philos);
}
