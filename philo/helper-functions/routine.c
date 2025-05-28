/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:22:03 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/28 10:28:42 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	philo_think(t_philosopher *philo)
{
	safe_print(philo, "is thinking");
}

static void	eating_process(t_philosopher *philo)
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
	safe_usleep(philo, philo->shared_data->time_to_eat);
}

static void	philo_eat(t_philosopher *philo)
{
	if (philo->shared_data->num_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		safe_print(philo, "has taken a fork");
		safe_usleep(philo, philo->shared_data->time_to_die);
		pthread_mutex_lock(&philo->shared_data->death_checker_mutex);
		philo->shared_data->someone_died = 1;
		pthread_mutex_unlock(&philo->shared_data->death_checker_mutex);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		eating_process(philo);
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
	safe_usleep(philo, philo->shared_data->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (death_checker(philo))
			break ;
		philo_think(philo);
		if (death_checker(philo))
			break ;
		philo_eat(philo);
		if (death_checker(philo))
			break ;
		philo_sleep(philo);
	}
	return (NULL);
}
