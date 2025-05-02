/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:41:37 by mdahani           #+#    #+#             */
/*   Updated: 2025/05/02 12:49:35 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	custom_error(char *err_msg)
{
	int i;
	i = 0;
	while (err_msg[i])
	{
		write(2, &err_msg[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}
