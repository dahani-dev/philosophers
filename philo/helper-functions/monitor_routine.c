/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:09:10 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/25 12:11:45 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
			if (get_time_ms() - data->philosopher[i].last_meal_time > data->time_to_die)
			{
				safe_print(&data->philosopher[i], "is dead\n");
				data->someone_died = 1;
				pthread_mutex_unlock(&data->monitor_mutex);
				return (NULL);
				// break ;
			}
			pthread_mutex_unlock(&data->monitor_mutex);
			i++;
		}
	}
	return (NULL);
}
