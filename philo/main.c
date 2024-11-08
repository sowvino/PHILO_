/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 13:05:16 by selango           #+#    #+#             */
/*   Updated: 2024-11-07 13:05:16 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		// Check if any character is not between '0' and '9'
		if (s[i] < '0' || s[i] > '9')
		{
			return (0); // Return 0 if non-digit character is found
		}
		i++;
	}
	return (1); // Return 1 if all characters are digits
}


int	valid_input_checker(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || !is_digit(argv[1])
		|| ft_atoi(argv[1]) < 0)
	{
        printf("Invalid input\n");
        return(1); 
	}
	if (ft_atoi(argv[2]) <= 0 || !is_digit(argv[2]) &&(argv[2]) <= 0 || !is_digit(argv[2]))
        return(write(2,"Invalid time_to_die\n",21),1);
    if (ft_atoi(argv[3]) <= 0 || !is_digit(argv[3]))
       return(write(2,"Invalid time_to_eat\n",21),1);
    if (ft_atoi(argv[4]) <= 0 || !is_digit(argv[4]))
        return(write(2,"Invalid time_to_sleep\n",23),1);
    if(!argv[5] || !is_digit(argv[5]))
        return(1); 
	return(0);
}
/*nbr_of_philo , time_to_die, time_to_eat, time_to_sleep, meals_fed*/
int	main(int argc, char **argv)
{
	pthread_mutex_t forks[PHILO_MAX];
    t_philo philos[PHILO_MAX];
	if (argc != 5 && argc != 6)
	{
		printf("Enter the correct input");
		return (1);
	}
    if(valid_input_checker(argv))
        return(1);
	
    return(0);  
}