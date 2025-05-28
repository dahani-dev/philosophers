/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:58:22 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/28 09:36:58 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int ac, char **av)
{
	t_shared_data	shared_data;
	int				init_result;

	if (ac != 5 && ac != 6)
	{
		custom_error("Error: Missing argument ==> [number_of_philosophers] "
			"[time_to_die] [time_to_eat] [time_to_sleep] "
			"[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	init_result = init_shared_data(&shared_data, ac, av);
	if (init_result == 0)
	{
		custom_error("Error: invalid data!\n");
		return (1);
	}
	else if (init_result == 1337)
		return (0);
	init_philosophers(&shared_data);
	create_threads_and_join(&shared_data);
	destroy_all_mutex(&shared_data);
	free(shared_data.forks);
	free(shared_data.philosopher);
	return (0);
}
