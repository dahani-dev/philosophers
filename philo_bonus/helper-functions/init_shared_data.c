/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:47:53 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/27 18:09:03 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

int	init_shared_data(t_shared_data *data, int ac, char **av)
{
	int	i;

	data->num_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		data->num_of_times_each_philosopher_must_eat = -1;
	if (data->num_philosophers <= 0 || data->time_to_die <= 0
	|| data->time_to_eat <= 0 || data->time_to_sleep <= 0 || (ac == 6
		&& data->num_of_times_each_philosopher_must_eat < 0))
		return (0);
	if ((ac == 6 && data->num_of_times_each_philosopher_must_eat == 0))
	{
		printf("No philosopher is required to eat any meals.\n");
		return (1337);
	}
	data->someone_died = 0;
	data->start_time = get_time_ms();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (!data->forks)
		return (0);
	i = 0;
	// sedit this
	while (i < data->num_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (1);
}
