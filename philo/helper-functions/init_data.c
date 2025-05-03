/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:47:53 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/02 21:42:45 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void init_data(t_shared_data *data, int ac, char **av)
{
    data->num_philosophers = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);

    if (ac == 6)
        data->num_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        data->num_of_times_each_philosopher_must_eat = -1;
    data->someone_died = 0;
}
