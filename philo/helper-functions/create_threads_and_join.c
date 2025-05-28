/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_and_join.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:27:49 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/28 09:35:35 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_threads_and_join(t_shared_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_create(&data->philosopher[i].thread, NULL, &routine,
			&data->philosopher[i]);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor_routine, data);
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(data->philosopher[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
