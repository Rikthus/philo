/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:53:52 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/26 17:24:30 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_drop_forks(t_philo *philo)
{
	release_fork(philo, DROP_F1);
	release_fork(philo, DROP_F2);
}

int	take_fork(t_philo *philo, int fork)
{
	if (philo->data->nb_forks == 1 && fork == TAKE_F2)
	{
		ft_usleep(philo->data->t_die, philo);
		return (0);
	}
	if (fork == TAKE_F1)
	{
		pthread_mutex_lock(&philo->data->mtx[philo->phi_id]);
		print_state(philo, TAKE_F1);
	}
	else
	{
		if (philo->phi_id == philo->data->nb_forks - 1)
			pthread_mutex_lock(&philo->data->mtx[0]);
		else
			pthread_mutex_lock(&philo->data->mtx[philo->phi_id + 1]);
		print_state(philo, TAKE_F2);
	}
	return (1);
}

void	release_fork(t_philo *philo, int fork)
{
	if (fork == DROP_F1)
		pthread_mutex_unlock(&philo->data->mtx[philo->phi_id]);
	else
	{
		if (philo->phi_id == philo->data->nb_forks - 1)
			pthread_mutex_unlock(&philo->data->mtx[0]);
		else
			pthread_mutex_unlock(&philo->data->mtx[philo->phi_id + 1]);
	}
}
