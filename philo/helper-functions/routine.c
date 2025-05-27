/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:22:03 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/27 10:52:19 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	philo_think(t_philosopher *philo)
{
	safe_print(philo, "is thinking");
}
static void	philo_eat(t_philosopher *philo)
{
	if (philo->shared_data->num_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		safe_print(philo, "has taken a fork");
		safe_usleep(philo, philo->shared_data->time_to_die * 1000);
		pthread_mutex_lock(&philo->shared_data->monitor_mutex);
		philo->shared_data->someone_died = 1;
		pthread_mutex_unlock(&philo->shared_data->monitor_mutex);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			safe_print(philo, "has taken a fork");
			pthread_mutex_lock(philo->right_fork);
			safe_print(philo, "has taken a fork");
		}
		else
		{
			usleep(1000);
			pthread_mutex_lock(philo->right_fork);
			safe_print(philo, "has taken a fork");
			pthread_mutex_lock(philo->left_fork);
			safe_print(philo, "has taken a fork");
		}
		safe_print(philo, "is eating");
		pthread_mutex_lock(&philo->shared_data->time_mutex);
		philo->last_meal_time = get_time_ms();
		pthread_mutex_unlock(&philo->shared_data->time_mutex);
		pthread_mutex_lock(&philo->shared_data->meals_eaten_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->shared_data->meals_eaten_mutex);
		safe_usleep(philo, philo->shared_data->time_to_eat * 1000);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
		}
		else
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			
		}		
	}
}

static void	philo_sleep(t_philosopher *philo)
{
	safe_print(philo, "is sleeping");
	safe_usleep(philo, philo->shared_data->time_to_sleep * 1000);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->shared_data->monitor_mutex);
		if (philo->shared_data->someone_died)
		{
			pthread_mutex_unlock(&philo->shared_data->monitor_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->shared_data->monitor_mutex);
		
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
