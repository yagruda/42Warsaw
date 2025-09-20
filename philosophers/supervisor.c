/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:58:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/19 18:34:49 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// TBD
void* supervisor_fn(void *arg)
{
	t_table* table = (t_table*) arg;
	(void)table;
	
	while(1)
	{
		// printf("Supervisor is checking philosophers...\n");
		sleep(5);
	}
	return NULL;
}