/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:50:15 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/23 23:15:10 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	if (!print_state(philo, EAT))
		return (0);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->data->mutex_eat);
	if (philo->data->max_eat > 0)
	{
		philo->nb_eat++;
		if (philo->nb_eat == philo->data->max_eat)
		{
			pthread_mutex_lock(&philo->data->mutex_end_diner);
			philo->data->full_eat++;
			pthread_mutex_unlock(&philo->data->mutex_end_diner);
		}
	}
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (!print_state(philo, SLEEP))
		return (0);
	ft_usleep(philo->data->t_sleep);
	return (1);
}

int	thinking(t_philo *philo)
{
	if (!print_state(philo, THINK))
		return (0);
	return (1);
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