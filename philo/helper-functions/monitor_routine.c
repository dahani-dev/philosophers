/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:10 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/29 18:23:24 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	monitor_check_death(t_shared_data *data)
{
	int			i;
	long long	current_time;
	long long	last_meal_time;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->time_mutex);
		current_time = get_time_ms();
		last_meal_time = data->philosopher[i].last_meal_time;
		pthread_mutex_unlock(&data->time_mutex);
		if (current_time - last_meal_time >= data->time_to_die
			&& data->num_philosophers > 1)
		{
			pthread_mutex_lock(&data->death_checker_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->death_checker_mutex);
			pthread_mutex_lock(&data->print_mutex);
			printf("%lld %d is dead\n", get_time_ms() - data->start_time,
				data->philosopher[i].id);
			pthread_mutex_unlock(&data->print_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	philosopher_meals_checker(t_shared_data *data)
{
	int	i;
	int	count;
	int	meals_eaten;

	i = 0;
	count = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->meals_eaten_mutex);
		meals_eaten = data->philosopher[i].meals_eaten;
		pthread_mutex_unlock(&data->meals_eaten_mutex);
		if (meals_eaten == data->num_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&data->meals_counter_mutex);
			count++;
			pthread_mutex_unlock(&data->meals_counter_mutex);
		}
		i++;
	}
	return (count);
}

void	*monitor_routine(void *arg)
{
	t_shared_data	*data;

	data = (t_shared_data *)arg;
	while (1)
	{
		if (death_checker(&data->philosopher[0]))
			break ;
		if (monitor_check_death(data))
			return (NULL);
		if (data->num_of_times_each_philosopher_must_eat > 0)
		{
			if (philosopher_meals_checker(data) >= data->num_philosophers)
			{
				pthread_mutex_lock(&data->death_checker_mutex);
				printf("All philosophers must eat all their meals\n");
				data->someone_died = 1;
				pthread_mutex_unlock(&data->death_checker_mutex);
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}
