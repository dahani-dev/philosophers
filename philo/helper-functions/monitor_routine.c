/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:10 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/27 10:22:38 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int philosopher_meals_checker(t_shared_data *data)
{
	int i;
	int count;
	int meals_eaten;

	i = 0;
	count = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->meals_checker_mutex);
		meals_eaten = data->philosopher[i].meals_eaten;
		pthread_mutex_unlock(&data->meals_checker_mutex);
		if (meals_eaten == data->num_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&data->meals_counter_mutex);
			count++;
			pthread_mutex_lock(&data->meals_counter_mutex);
		}
		i++;
	}
	return (count);	
}

void	*monitor_routine(void *arg)
{
	t_shared_data	*data;
	int				i;
	long long		current_time;
	long long		last_meal_time;

	data = (t_shared_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->monitor_mutex);
		if (data->someone_died)
		{
			pthread_mutex_unlock(&data->monitor_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->monitor_mutex);
		
		i = 0;
		while (i < data->num_philosophers)
		{
			pthread_mutex_lock(&data->time_mutex);
			current_time = get_time_ms();
			last_meal_time = data->philosopher[i].last_meal_time;
			pthread_mutex_unlock(&data->time_mutex);
			if (current_time - last_meal_time >= data->time_to_die)
			{
				pthread_mutex_lock(&data->monitor_mutex);
				if (!data->someone_died)
				{
					safe_print(&data->philosopher[i], "is dead\n");
					data->someone_died = 1;	
				}
				pthread_mutex_unlock(&data->monitor_mutex);
				return (NULL);
			}
			i++;
		}
		if (data->num_of_times_each_philosopher_must_eat > 0)
		{
			if (philosopher_meals_checker(data) >= data->num_philosophers)
			{
				pthread_mutex_lock(&data->monitor_mutex);
				if (!data->someone_died)
				{
					printf("All philosophers must eat all their meals\n");
					data->someone_died = 1;
				}
				pthread_mutex_unlock(&data->monitor_mutex);
				return (NULL);
			}
		}
	}
	return (NULL);
}
