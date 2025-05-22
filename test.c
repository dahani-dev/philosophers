/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:26:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/07 13:33:27 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int x = 0;

pthread_mutex_t mutex;

void	*my_routine(void *walo)
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL); 
}

int	main(void)
{
	pthread_t	new_thread[4];

	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 4; i++)
	{
		pthread_create(&new_thread[i], NULL, &my_routine, NULL);
		printf("Thread %d created\n", i + 1);
	}
	for (int i = 0; i < 4; i++)
	{
		pthread_join(new_thread[i], NULL);
		printf("Thread %d joined\n", i + 1);
	}
	
	printf("All threads are joined\n");
	pthread_mutex_destroy(&mutex);
	printf("x = %d\n", x);
}
