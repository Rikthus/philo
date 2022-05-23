/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:50:15 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/23 12:01:15 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int	check_end(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->mutex_end_diner);
// 	if (philo->data->end_diner == 1)
// 	{
// 		check_drop_forks(philo);
// 		return (0);
// 	}
// 	pthread_mutex_unlock(&philo->data->mutex_end_diner);
// 	return (1);
// }

// int	eating(t_philo *philo)
// {
// 	if (!print_state(philo, EAT))
// 		return (0);
// 	ft_usleep(philo->data->t_eat);
// 	philo->last_eat_time = get_time();
// 	if (philo->data->max_eat > 0)
// 	{
// 		philo->nb_eat++;
// 		if (philo->nb_eat == philo->data->max_eat)
// 		{
// 			pthread_mutex_lock(&philo->data->mutex_end_diner);
// 			philo->data->full_eat++;
// 			pthread_mutex_unlock(&philo->data->mutex_end_diner);
// 		}
// 	}
// 	return (1);
// }

// int	sleeping(t_philo *philo)
// {
// 	if (!print_state(philo, SLEEP))
// 		return (0);
// 	ft_usleep(philo->data->t_sleep);
// 	return (1);
// }

int	thinking(t_philo *philo)
{
	if (!print_state(philo, THINK))
		return (0);
	return (1);
}

