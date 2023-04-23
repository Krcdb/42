/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:55:27 by memartin          #+#    #+#             */
/*   Updated: 2020/12/08 09:49:24 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define SUCCES 1
# define FAILURE 0

typedef struct			s_parameters
{
	size_t				nb_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				nb_meal_needed;
	int					b_dead;
	struct timeval		time_start;
}						t_parameters;

typedef struct			s_philo
{
	size_t				nb;
	size_t				nb_meal;
	int					done;
	pthread_mutex_t		*r_fork_m;
	pthread_mutex_t		*l_fork_m;
	pthread_mutex_t		*display_m;
	pthread_mutex_t		*eating_death_m;
	t_parameters		*param;
	struct timeval		time_last_meal;
	struct s_philo		*next;
}						t_philo;

typedef struct			s_philo_one
{
	t_parameters		*param;
	t_philo				*philo;
}						t_philo_one;

int						display_error(char *str);
int						display_state(t_philo *philo, char *str);
int						clear_data(t_philo_one *data);
int						init_param(t_parameters *param, char **av, int ac);
int						init_philo(t_philo_one *data);
void					*routine(void *arg);
void					supervisor(t_philo_one *data);

size_t					get_time_us(struct timeval start);
size_t					get_time_ms(struct timeval start);
void					ft_usleep(size_t n);

size_t					ft_strlen(const char *str);
int						atos_verif(size_t *nb, char *str);

#endif