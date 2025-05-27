/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:22:51 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/27 10:42:50 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	safe_usleep(t_philosopher *philo, int time)
{
	int	divided_time;

	divided_time = 0;
	while (divided_time <= time)
	{
		pthread_mutex_lock(&philo->shared_data->monitor_mutex);
		if (philo->shared_data->someone_died)
		{
			pthread_mutex_unlock(&philo->shared_data->monitor_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->shared_data->monitor_mutex);
		usleep(1000);
		divided_time += 1000;
	}
}
