/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:57:48 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/23 16:58:10 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	philo->starting_time = get_time();
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->data->mutex_eat);
	if (philo->phi_id % 2 == 0)
		ft_usleep(philo->data->t_eat);
	while (1)
	{
		if (!event(philo, TAKE_F1))
			break ;
		if (!event(philo, TAKE_F2))
			break ;
		// if (!event(philo, EAT))
		// 	break ;
		check_drop_forks(philo);
		if (!event(philo, SLEEP))
			break ;
		if (!event(philo, THINK))
			break ;
	}
	check_drop_forks(philo);
	return (NULL);
}

int	launch_threads(t_philo **philo_tab)
{
	int			i;
	pthread_t	*th;

	i = 0;
	th = malloc(sizeof(pthread_t) * philo_tab[0]->data->nb_forks);
	if (!th)
		return (0);
	while (i < philo_tab[0]->data->nb_forks)
	{
		if (pthread_create(&th[i], NULL, &routine, &philo_tab[0][i]) != 0)
			return (0);
		i++;
	}
	monitoring(philo_tab);
	i = 0;
	while (i < philo_tab[0]->data->nb_forks)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (0);
		i++;
	}
	free(th);
	return (1);
}

