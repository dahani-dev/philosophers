/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:45:38 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/26 11:34:20 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_atoi_process(char *str, int i, long *result, int *sign_counter)
{
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		if (str[i] == '+')
			(*sign_counter)++;
		if (*sign_counter > 1)
			return (-1);
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i] - '0');
		if (*result > 2147483647)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;
	int		sign_counter;

	i = 0;
	sign = 1;
	result = 0;
	sign_counter = 0;
	while (str[i])
	{
		while (str[i] && str[i] <= 32)
			i++;
		if (ft_atoi_process(str, i, &result, &sign_counter) == -1)
			return (-1);
		i++;
	}
	return ((int)result * sign);
}
