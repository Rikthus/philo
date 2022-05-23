/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:45:45 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/23 17:30:45 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					max_eat;
	int					nb_forks;
	int					*forks;
	int					full_eat;
	int					death;
	int					end_diner;
	pthread_mutex_t		*mtx;
	pthread_mutex_t		mutex_chat;
	pthread_mutex_t		mutex_death;
	pthread_mutex_t		mutex_eat;
	pthread_mutex_t		mutex_end_diner;
}	t_data;

typedef struct	s_philo
{
	int					phi_id;
	int					fork1;
	int					fork2;
	int					nb_eat;
	long long unsigned	last_eat_time;
	long long unsigned	starting_time;
	t_data				*data;
}	t_philo;

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define TAKE_F1 5
# define TAKE_F2 6
# define DROP_F1 7
# define DROP_F2 8

# define DEBUG printf("ok\n");

// PARSING
int					parsing(int argc, char **argv);

// INIT
int					init(t_philo **philo_tab, int argc, char **argv);

// INIT_DATA
t_data				*init_data(int argc, char **argv);

// TH_HANDLER
int					launch_threads(t_philo **philo_tab);

// MONITORING
void				monitoring(t_philo **philo_tab);

// EVENT_CTRL
int					event(t_philo *philo, int event);

// EVENTS
int					eating(t_philo *philo);
int					thinking(t_philo *philo);
int					sleeping(t_philo *philo);
int					print_state(t_philo *philo, int state);

// EVENT_FORK
void				check_drop_forks(t_philo *philo);
int					take_fork(t_philo *philo, int fork);
void				release_fork(t_philo *philo, int fork);

// CLEANER
void				clean_data(t_data **data);
void				clean_philos(t_philo **philo_tab);

// UTILS
int					ft_atoi(char *str);
int					ft_strcmp(char *s1, char *s2);
void				ft_usleep(int time);
long long unsigned	get_time(void);

#endif
