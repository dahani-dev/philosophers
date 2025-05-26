/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:22:03 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/25 20:54:21 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_think(t_philosopher *philo)
{
	safe_print(philo, "is thinking");
}
void	philo_eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(philo->right_fork);
	safe_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	safe_print(philo, "has taken a fork");
	safe_print(philo, "is eating");
	pthread_mutex_lock(&philo->shared_data->time_mutex);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->shared_data->time_mutex);
	philo->meals_eaten++;
	usleep(philo->shared_data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philosopher *philo)
{
	safe_print(philo, "is sleeping");
	usleep(philo->shared_data->time_to_sleep * 1000);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->shared_data->someone_died)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
