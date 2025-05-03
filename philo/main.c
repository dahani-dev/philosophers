/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:58:22 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/03 16:14:22 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int ac, char **av)
{
	t_shared_data	shared_data;
	int				i;

	if (ac != 5 && ac != 6)
		custom_error("Error: Missing argument ==> [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
	init_shared_data(&shared_data, ac, av);
	init_philosophers(&shared_data);
	i = 0;
	while (i < shared_data.num_philosophers)
	{
		printf("id of philo: %d\n	left fork: %p\n	left fork: %p\n",
			shared_data.philosopher[i].id, shared_data.philosopher->left_fork,
			shared_data.philosopher->right_fork);
		i++;
	}
}
