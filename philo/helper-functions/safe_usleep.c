/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:22:51 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/28 09:13:35 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	safe_usleep(t_philosopher *philo, long long time)
{
	long long	start_time;

	start_time = get_time_ms();
	while (!death_checker(philo) && (get_time_ms() - start_time) < time)
	{
		if (death_checker(philo))
			return ;
		usleep(50);
	}
}
