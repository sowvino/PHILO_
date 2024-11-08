/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 13:22:33 by selango           #+#    #+#             */
/*   Updated: 2024-11-07 13:22:33 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i ;
    i =0;
    if(!str)
        return (0);
    while(str[i] != '\0')
        i++;
    return(i);
}

long ft_atoi(char *str)
{
	long nb;
	int					i;

	nb = 0;
	i = 0;
	while ((str[i] >= 9  && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}
size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		error_msg("time_stamp error\n");
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

