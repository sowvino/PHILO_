/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 13:07:29 by selango           #+#    #+#             */
/*   Updated: 2024-11-07 13:07:29 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   PHILO_H
#define   PHILO_H

#ifndef PHILO_MAX
#define  PHILO_MAX 200 
#endif

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
    pthread_t thread;
    int philo_nbr;
    int philo_id;
    int eating;
    int dead;
    int num_times_to_eat;
    int meals_eaten;
    size_t  time_to_eat;
    size_t  time_to_die;
    size_t  time_to_sleep;
    size_t  start_time;
    size_t  last_meal;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *meal_lock;
}           t_philo;

typedef     struct s_data
{
    int dead_flag;
    pthread_mutex_t     write_lock;
    pthread_mutex_t     dead_lock;
    pthread_mutex_t     meal_lock;
    pthread_mutex_t        *forks;
    t_philo *philos;
} t_data;

void parse_data(t_philo *philos,char **argv);
int ft_strlen(char *str);
long ft_atoi(char *str);
size_t	get_current_time(void);


#endif

