/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:37:34 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/23 22:47:48 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_data(t_data **data)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = *data;
	while (i < tmp->nb_forks)
	{
		pthread_mutex_destroy(&tmp->mtx[i]);
		i++;
	}
	free(tmp->mtx);
	pthread_mutex_destroy(&tmp->mutex_chat);
	pthread_mutex_destroy(&tmp->mutex_death);
	pthread_mutex_destroy(&tmp->mutex_end_diner);
	pthread_mutex_destroy(&tmp->mutex_eat);
	free(tmp);
}

void	clean_philos(t_philo **philo_tab)
{
	clean_data(&philo_tab[0]->data);
	free(*philo_tab);
}
