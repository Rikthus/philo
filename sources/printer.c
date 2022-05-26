/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:16:20 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/26 17:17:29 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_death);
	if (philo->data->death == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex_death);
	return (0);
}

static	int	end_diner(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_end_diner);
	if (philo->data->end_diner == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_end_diner);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex_end_diner);
	return (0);
}

int	print_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->data->mutex_chat);
	if (death(philo) || end_diner(philo))
	{
		pthread_mutex_unlock(&philo->data->mutex_chat);
		return (0);
	}
	if (state == TAKE_F1 || state == TAKE_F2)
		printf("[%llu] %d has taken a fork\n",
			get_time() - philo->starting_time, philo->phi_id + 1);
	if (state == EAT)
		printf("[%llu] %d is eating\n",
			get_time() - philo->starting_time, philo->phi_id + 1);
	if (state == SLEEP)
		printf("[%llu] %d is sleeping\n",
			get_time() - philo->starting_time, philo->phi_id + 1);
	if (state == THINK)
		printf("[%llu] %d is thinking\n",
			get_time() - philo->starting_time, philo->phi_id + 1);
	pthread_mutex_unlock(&philo->data->mutex_chat);
	return (1);
}
