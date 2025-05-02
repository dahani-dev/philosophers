/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:26:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/01 21:33:49 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*my_turn(void *walo)
{
    int i = 1;
	while (1)
	{
		sleep(1);
		printf("[%d] my turn \n", i);
        i++;
        if (i == 5)
            break ;        
	}
	return (NULL);
}
void	your_turn(void)
{
    int i = 1;
	while (1)
	{
		sleep(1);
		printf("[%d] your turn \n", i);
        i++;
	}
}

int	main(void)
{
	pthread_t	new_thread;

	pthread_create(&new_thread, NULL, my_turn, NULL);
	your_turn();
}
