/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:58:22 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/26 10:49:06 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int ac, char **av)
{
	t_shared_data	shared_data;
	int				i;
	pthread_t		monitor_thread;

	if (ac != 5 && ac != 6)
		custom_error("Error: Missing argument ==> [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
	if (!init_shared_data(&shared_data, ac, av))
		custom_error("Error: invalid data!\n");
	init_philosophers(&shared_data);
	i = 0;
	while (i < shared_data.num_philosophers)
	{
		pthread_create(&shared_data.philosopher[i].thread, NULL, &routine,
			&shared_data.philosopher[i]);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor_routine, &shared_data);
	i = 0;
	while (i < shared_data.num_philosophers)
	{
		pthread_join(shared_data.philosopher[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < shared_data.num_philosophers)
	{
		pthread_mutex_destroy(&shared_data.forks[i]);
		i++;
	}
	free(shared_data.forks);
	free(shared_data.philosopher);
	pthread_mutex_destroy(&shared_data.print_mutex);
	pthread_mutex_destroy(&shared_data.monitor_mutex);
	pthread_mutex_destroy(&shared_data.time_mutex);
	pthread_mutex_destroy(&shared_data.meals_checker_mutex);
	return (0);
}
