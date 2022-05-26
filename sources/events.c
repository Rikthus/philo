/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:50:15 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/26 17:16:17 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	if (!print_state(philo, EAT))
		return (0);
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->data->mutex_eat);
	ft_usleep(philo->data->t_eat, philo);
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
	ft_usleep(philo->data->t_sleep, philo);
	return (1);
}

int	thinking(t_philo *philo)
{
	if (!print_state(philo, THINK))
		return (0);
	return (1);
}
