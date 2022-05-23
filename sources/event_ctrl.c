/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:52:37 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/23 14:07:56 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	event(t_philo *philo, int event)
{
	// if (event == TAKE_F1)
	// 	return (take_fork(philo, TAKE_F1));
	// if (event == TAKE_F2)
	// 	return (take_fork(philo, TAKE_F2));
	// if (event == EAT)
	// 	return (eating(philo));
	if (event == THINK)
		return (thinking(philo));
	if (event == SLEEP)
		return (sleeping(philo));
	return (0);
}

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
		printf("[%lld] %d has taken a fork\n",
				get_time() - philo->starting_time, philo->phi_id);
	if (state == EAT)
		printf("[%lld] %d is eating\n",
				get_time() - philo->starting_time, philo->phi_id);
	if (state == SLEEP)
		printf("[%lld] %d is sleeping\n",
				get_time() - philo->starting_time, philo->phi_id);
	if (state == THINK)
		printf("[%lld] %d is thinking\n",
				get_time() - philo->starting_time, philo->phi_id);
	pthread_mutex_unlock(&philo->data->mutex_chat);
	return (1);
}
