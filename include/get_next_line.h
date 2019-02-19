/*
** get_next_line.h for  in /home/adel.afassi/CPE_2016_getnextline
**
** Made by adel afassi
** Login   <adel.afassi@epitech.net>
**
** Started on  Sun Jan 15 14:08:40 2017 adel afassi
** Last update Sun Feb 26 15:48:44 2017 John Doe
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (2)
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

struct	s_variable
{
  char	*buf;
  char	*line;
  int	z;
  int	i;
  int	l;
};

char	*get_next_line(const int fd);
char	*reallocation(char *s, int size);
int	check_line_break(char *str);
char	*my_strcat(char *str_save, struct s_variable *var, const int fd);

#endif
