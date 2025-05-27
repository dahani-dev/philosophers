/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:48:49 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/27 16:01:15 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	safe_print(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&philo->shared_data->print_mutex);
	if (death_checker(philo))
	{
		pthread_mutex_unlock(&philo->shared_data->print_mutex);
		return ;
	}
	printf("%lld philo: %d %s\n", get_time_ms()
		- philo->shared_data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->shared_data->print_mutex);
}
