/*
** get_next_line.c for  in /home/adel/delivery/CPE_2016_matchstick/gnl/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Feb 26 14:49:34 2017 John Doe
** Last update Mon Feb 27 14:18:43 2017 John Doe
*/

#include "my.h"

char	*reallocation(char *s, int size)
{
  int	i;
  char	*str;
  int	a;

  i = 0;
  a = my_strlen(s);
  if ((str = xmalloc(a + size)) == NULL)
    return (NULL);
  while (s[i] != '\0')
    {
      str[i] = s[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

int	check_line_break(char *str)
{
  int	i;
  int	find;

  find = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	find++;
      i++;
    }
  return (find);
}

char		*last_copy(char *str_save, char *line)
{
  int		i;
  static	int	nb_save = 0;

  i = 0;
  while (str_save[nb_save] != '\0' && str_save[nb_save] != '\n')
    {
      line[i] = str_save[nb_save];
      line[i + 1] = '\0';
      if ((line = reallocation(line, 4)) == NULL)
	return (NULL);
      i++;
      nb_save++;
    }
  line[i] = '\0';
  if (str_save[nb_save] == '\0' && line[0] == '\0')
    return (NULL);
  nb_save++;
  return (line);
}

char		*my_strcat(char *str_save, struct s_variable *var, const int fd)
{
  static int	p = 1;
  static int	nb_copy = 0;

  var->l = 0;
  var->z = 0;
  if ((var->buf = xmalloc(READ_SIZE + 3)) == NULL)
    return (NULL);
  while (var->l == 0 && p != 0)
    {
      if ((str_save = reallocation(str_save, READ_SIZE + 4)) == NULL)
	return (NULL);
      if ((p = read(fd, var->buf, READ_SIZE)) == -1)
	return (NULL);
      if (p == 0)
	return (NULL);
      var->buf[p] = '\0';
      while (p != 0 && var->buf[var->z] != '\0')
	str_save[nb_copy++] = var->buf[var->z++];
      var->z = 0;
      var->l = check_line_break(var->buf);
      str_save[nb_copy] = '\0';
    }
  str_save[nb_copy] = '\0';
  free(var->buf);
  return (str_save);
}

char	*get_next_line(const int fd)
{
  struct s_variable	var;
  static int	b = 0;
  static char	*str_save;

  if ((var.line = xmalloc(10)) == NULL)
    return (NULL);
  if (b == 0)
    {
      if ((str_save = xmalloc(READ_SIZE + 5)) == NULL)
	return (NULL);
      str_save[0] = '\0';
      b = 1;
    }
  if ((str_save = my_strcat(str_save, &var, fd)) == NULL)
    return (NULL);
  if ((var.line = last_copy(str_save, var.line)) == NULL)
    return (NULL);
  return (var.line);
}
