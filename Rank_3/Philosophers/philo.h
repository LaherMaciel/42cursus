/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:13 by lahermaciel       #+#    #+#             */
/*   Updated: 2025/07/24 16:25:09 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define CLEAR "\033c"
# define RED "\033[1;31m"
# define MAGENTA "\033[0;35m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define GRAY "\033[1;90m"
# define DEFAULT_COLOR "\033[0m"
# define BOLTED_DEFAULT_COLOR "\033[1;0m"
# define BOLD_BLACK "\033[1;30m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

typedef struct s_table			t_table;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	int				left_fork;
	int				right_fork;
	int				num_of_times_eaten;
	int				time_multiplier;
	long int		current_time;
	long int		start_time;
	long int		time_that_eaten;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	time_mutex;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	int				is_dead;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_philos;
	int				num_of_times_to_eat;
	t_philo			**philos;
	pthread_t		*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	print_mutex;
}	t_table;

t_philo		**init_philo(int argc, char **argv);
int			ft_isdigit(int i);
int			ft_isdigit2(char *str);
size_t		ft_atoi(const char *str);
void		*ft_calloc(size_t n, size_t size);
void		print_philoinfo(t_philo *philo);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *a);
void		*start_routine(void *base_struct);
t_philo		**free_philos(t_philo **philos, int num_of_philos);
t_philo		*init_philo_values(int i, t_table *table);
long int	time_in_ms(void);
t_philo		*printphilosactions(t_philo *philo, int flag);
t_table		*init_table(int argc, char **argv);
t_table		*free_table(t_table *table);
int			is_death(t_philo *philo);
t_philo		*monitoring(t_philo *philo);
int			get_eaten_count(t_table *table, int i);
int			all_philos_ate_enough(t_table *table);
int			check_all_philos_death(t_table *table);
void		join_philos_threads(t_table *table, int numb_of_philos);
void		free_all(t_philo **philos, t_table *table);
int			handle_one_philo(t_table *table);
void		create_philo_threads(t_philo **philos, t_table *table,
				int numb_of_philos);
void		precise_sleep(long duration_ms, t_table *table);
void		clean_up(t_philo *philo, int unlock_left, int unlock_right);
int			should_exit(t_philo *philo);
void		eat_print_fork(t_philo *philo);
void		eat_print_died(t_philo *philo);
void		eat_print_eating(t_philo *philo);
t_philo		*think(t_philo *philo);
int			lock_even_forks(t_philo *philo);
int			lock_odd_forks(t_philo *philo);
int			should_break(t_philo *philo, int eaten);
void		routine_loop(t_philo *philo);

#endif