/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:10 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/07 18:44:01 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_shared_data	*data;
	int				i;

	data = (t_shared_data *)arg;
	while (!data->someone_died)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			// pthread_mutex_lock(&data->print_mutex);
			// pthread_mutex_lock(&data->philosopher[i].);
			if (data->time_to_die < get_time_ms()
				- data->philosopher[i].last_meal_time)
			{
				pthread_mutex_lock(&data->death_lock);
				data->someone_died = 1;
				printf("Philosopher: %d Runnig time: %lld is died\n",
					data->philosopher->id, get_time_ms() - data->start_time);
				pthread_mutex_unlock(&data->death_lock);
				return (NULL);
			}
			// pthread_mutex_unlock(&data->print_mutex);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
