/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:48:49 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/07 11:36:11 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	safe_print(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&philo->shared_data->print_mutex);
	if (!philo->shared_data->someone_died)
		printf("Philosopher: %d Runnig time: %lld is %s\n", philo->id, get_time_ms()
			- philo->shared_data->start_time, msg);
	pthread_mutex_unlock(&philo->shared_data->print_mutex);
}
