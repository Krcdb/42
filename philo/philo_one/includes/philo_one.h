/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:16:51 by memartin          #+#    #+#             */
/*   Updated: 2020/07/29 15:25:26 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_ONE_H_
# define _PHILO_ONE_H_

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <inttypes.h>



typedef struct		s_data
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				m_limit;
	struct timeval	time;
}					t_data;

void		print_str(char *s);
int			atoi_boi(const char *str);
int			is_full_digit(char *s);
char		*ltoa(intmax_t n);

#endif
