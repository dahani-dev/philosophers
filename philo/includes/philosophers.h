/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:59:59 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/02 21:44:34 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_shared_data	t_shared_data;
typedef struct s_philosopher
{
	int							id;
	int							meals_eaten;
	long long					last_meal_time;
	pthread_t					thread;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;
	t_shared_data				*shared_data;
}								t_philosopher;

typedef struct s_shared_data
{
	int							num_philosophers;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							num_of_times_each_philosopher_must_eat;
	int							someone_died;
	long long					start_time;
	pthread_mutex_t				print_mutex;
	pthread_mutex_t				*forks;
	t_philosopher				*philosopher;
}								t_shared_data;

void	custom_error(char *err_msg);
void init_data(t_shared_data *data, int ac, char **av);
int	ft_atoi(const char *str);

#endif