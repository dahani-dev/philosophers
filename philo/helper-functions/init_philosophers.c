/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:50:48 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/03 16:00:36 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philosophers(t_shared_data *data)
{
	int i;

	i = 0;
	data->philosopher = malloc(sizeof(t_philosopher) * data->num_philosophers);
	while (i < data->num_philosophers)
	{
		data->philosopher[i].id = i + 1;
		data->philosopher[i].meals_eaten = 0;
		data->philosopher[i].last_meal_time = 0;
		data->philosopher[i].left_fork = &data->forks[i];
		data->philosopher[i].right_fork = &data->forks[(i + 1)
			% data->num_philosophers];
		data->philosopher[i].shared_data = data;
		i++;
	}
}
