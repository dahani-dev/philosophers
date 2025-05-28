/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:21:20 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/28 10:21:46 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	death_checker(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->shared_data->death_checker_mutex);
	if (philo->shared_data->someone_died)
	{
		pthread_mutex_unlock(&philo->shared_data->death_checker_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->shared_data->death_checker_mutex);
	return (0);
}
