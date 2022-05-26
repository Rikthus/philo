/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:53:06 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/26 17:12:56 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	long int	nb;
	int			i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nb = nb * 10 + (str[i] - 48);
		if (nb > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_usleep(int time, t_philo *philo)
{
	(void)philo;
	usleep(time * 1000);
}

long long unsigned	get_time(void)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	return (timer.tv_sec * 1000 + timer.tv_usec / 1000);
}
