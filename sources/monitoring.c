/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:06:13 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/26 17:12:00 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	is_dead(t_philo **philo_tab, int nb_philo, int t_die)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		usleep(1);
		pthread_mutex_lock(&philo_tab[0]->data->mutex_eat);
		if (philo_tab[0][i].last_eat_time + t_die < get_time())
		{
			pthread_mutex_unlock(&philo_tab[0]->data->mutex_eat);
			pthread_mutex_lock(&philo_tab[0]->data->mutex_death);
			philo_tab[0]->data->death = 1;
			pthread_mutex_unlock(&philo_tab[0]->data->mutex_death);
			pthread_mutex_lock(&philo_tab[0]->data->mutex_chat);
			printf("[%llu] %d died\n",
				get_time() - philo_tab[0]->starting_time, i + 1);
			pthread_mutex_unlock(&philo_tab[0]->data->mutex_chat);
			return (1);
		}
		pthread_mutex_unlock(&philo_tab[0]->data->mutex_eat);
		i++;
	}
	return (0);
}

void	monitoring(t_philo **philo_tab)
{
	while (1)
	{
		usleep(1);
		pthread_mutex_lock(&philo_tab[0]->data->mutex_end_diner);
		if (philo_tab[0]->data->full_eat == philo_tab[0]->data->nb_forks)
		{
			philo_tab[0]->data->end_diner = 1;
			pthread_mutex_unlock(&philo_tab[0]->data->mutex_end_diner);
			break ;
		}
		pthread_mutex_unlock(&philo_tab[0]->data->mutex_end_diner);
		if (is_dead(philo_tab, philo_tab[0]->data->nb_forks,
				philo_tab[0]->data->t_die))
			break ;
	}
}
