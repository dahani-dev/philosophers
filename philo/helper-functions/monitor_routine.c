/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:10 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/25 20:00:51 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int philosopher_meals_checker(t_shared_data *data)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < data->num_philosophers)
	{
		if (data->philosopher[i].meals_eaten == data->num_of_times_each_philosopher_must_eat)
			count++;
		i++;
	}
	return (count);	
}

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
			pthread_mutex_lock(&data->monitor_mutex);
			if (get_time_ms()
				- data->philosopher[i].last_meal_time >= data->time_to_die)
			{
				safe_print(&data->philosopher[i], "is dead\n");
				data->someone_died = 1;
				pthread_mutex_unlock(&data->monitor_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->monitor_mutex);
			i++;
		}
		pthread_mutex_lock(&data->meals_checker_mutex);
		if (philosopher_meals_checker(data) == data->num_philosophers)
		{
			printf("rahom salaw\n");
			data->someone_died = 1;
			pthread_mutex_unlock(&data->meals_checker_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->meals_checker_mutex);
	}
	return (NULL);
}
