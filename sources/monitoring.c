/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:06:13 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/23 12:13:17 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	monitoring(t_philo **philo_tab)
{
	while (1)
	{
		pthread_mutex_lock(&philo_tab[0]->data->mutex_end_diner);
		if (philo_tab[0]->data->full_eat == philo_tab[0]->data->nb_forks)
	}
}