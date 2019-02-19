/*
** my.h for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 20:06:23 2017 John Doe
** Last update Sun Feb 26 18:34:10 2017 John Doe
*/

#ifndef MY_H_
# define MY_H_

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_check
{
int		l;
char		*buf;
int		nope;
int		check;
}		t_check;

int		find_the_line(char **map, int  stick_remove, int version);
int		algorithm(int stick_on_all_map, int match_max);
int		number_of_all_stick(char **map);
int		victory(char **map, int winner);
int		all_stick(char **map);
int		xrandom(int minimum, int maximum, int old_nb);
char		**ia_player(char **map, int match);
void		shorcut3_player(int line_seizure, int matche, char ** map);
void		shorcut3_ia(int line_seizure, int matche, char ** map);
int		shorcut2(char *buf);
int		shorcut(int l, int match);
void		print_prompt_player(int matche, int line_seizure);
void		print_prompt_ia(int matche, int line_seizure);
int		matchstick(char **av);
int		number_of_stick(char *line);
char		*get_line(int i);
int		check_invalid_match(int matche, int line, char **map);
int		check_invalid_line(int line);
int		check_wrong_char(char *buf);
int		print_error_message(int l, int matche);
char		**human_player(char **map, int line, int nb);
char		*put_stick(char *map, int stick);
int		last_line_size(int line);
void		print_map(char **map);
void		print_space(int space);
void		print_stars(int nb);
int		my_puterror(char *str);
void		my_putchar_error(char c);
void		my_putchar(char c);
int		my_putnbr(int nb);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
char		**put_stick_map(int line);
char		*xmalloc(int size);
char		**tmalloc(int size);
char		**tab_malloc(int line);

#endif /* !MY_H_*/
