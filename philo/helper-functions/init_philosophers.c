/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:50:48 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/25 15:58:28 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philosophers(t_shared_data *data)
{
	int i;

	data->philosopher = malloc(sizeof(t_philosopher) * data->num_philosophers);
	if (!data->philosopher)
		return ;
	i = 0;
	while (i < data->num_philosophers)
	{
		data->philosopher[i].id = i + 1;
		data->philosopher[i].meals_eaten = 0;
		data->philosopher[i].last_meal_time = data->start_time;
		data->philosopher[i].left_fork = &data->forks[i];
		data->philosopher[i].right_fork = &data->forks[(i + 1)
			% data->num_philosophers];
		data->philosopher[i].shared_data = data;
		i++;
	}
}
