/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 10:46:38 by selango           #+#    #+#             */
/*   Updated: 2024-11-08 10:46:38 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void parse_data(t_philo *philos,char **argv)
{

  philos->time_to_die = ft_atoi(argv[2]);
  philos->time_to_eat = ft_atoi(argv[3]);
  philos->time_to_sleep = ft_atoi(argv[4]);
  if(argv[5])
    philos->num_times_to_eat = ft_atoi(argv[5]);
  else
    philos->num_times_to_eat = -1;
}
void init_philo(t_philo *philos,t_data *dinner_data,char **argv)
{
    int i;
    i =0;
    int philo_count;
    philo_count = ft_atoi(argv[1]);
    while(i < philo_count)
    {
        philos[i].philo_id = i + 1 ;
        philos[i].eating = 0;
        philos[i].meals_eaten =0;
        parse_data(&philos[i],argv);
        philos[i].start_time = get_current_time();
        philos[i].last_meal = get_current_time();
        philos[i].dead = &dinner_data->dead_flag;
        philos[i].write_lock = &dinner_data->write_lock;
        philos[i].dead_lock = &dinner_data->dead_lock;
        philos[i].meal_lock = &dinner_data->meal_lock;
        philo[i].l_lock = &forks[i];
        if(i ==0)
          philos[i].r_fork = &dinner_data->forks[philos[i].philo_nbr - 1];
        else
          philos[i].r_fork = &dinner_data->forks[i -1];
        i++;
    }
}
void init_forks(t_data *dinner_data,char **argv)
{
  int i;
  i =0;
  while(i < ft_atoi(argv[1]))
  {
    pthread_mutex_init(&dinner_data->forks[i],NULL);
    i++;
  }
}

void init_dinner_data(t_data *dinner_data,t_philos *philos)
{
  dinner_data->dead_flag =0;
  dinner_data->philos = philos;
  pthread_mutex_init(&dinner_data->write_lock,NULL);
  pthread_mutex_init(&dinner_data->meal_lock,NULL);
  pthread_mutex_init(&dinner_data->dead_lock,NULL);
}
void data_init(t_philo *philos,t_data *dinner_data,char **argv)
{
  init_dinner_data(dinner_data,philos); 
  init_forks(dinner_data,argv);
  init_philo(philos,dinner_data,argv);
 
}

