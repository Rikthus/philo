/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:57:48 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/26 17:22:51 by maxperei         ###   ########lyon.fr   */
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
	if (philo->phi_id % 2 == 1)
		ft_usleep(philo->data->t_eat, philo);
	while (1)
	{
		if (!take_fork(philo, TAKE_F1) || !take_fork(philo, TAKE_F2))
			break ;
		if (!eating(philo))
			break ;
		check_drop_forks(philo);
		if (!thinking(philo))
			break ;
		if (!sleeping(philo))
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
	ft_usleep(10, philo_tab[0]);
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
