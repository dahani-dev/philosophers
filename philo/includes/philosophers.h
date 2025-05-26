/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:59:59 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/25 19:39:41 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	pthread_mutex_t				monitor_mutex;
	pthread_mutex_t				time_mutex;
	pthread_mutex_t				meals_checker_mutex;
	t_philosopher				*philosopher;
}								t_shared_data;

void							custom_error(char *err_msg);
int								init_shared_data(t_shared_data *data, int ac,
									char **av);
void							init_philosophers(t_shared_data *data);
int								ft_atoi(const char *str);
void							*routine(void *arg);
void							safe_print(t_philosopher *philo, char *msg);
long long						get_time_ms(void);
void							*monitor_routine(void *arg);

#endif