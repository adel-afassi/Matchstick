/*
** error_handling.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 17:10:29 2017 John Doe
** Last update Mon Feb 27 14:20:16 2017 John Doe
*/

#include "my.h"

int	check_wrong_char(char *buf)
{
  int	i;
  int	z;

  z = 0;
  i = 0;
  if (buf == NULL || buf[0] == '\n' || buf[0] == '\0')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (buf[0] == '-')
    i++;
  while (buf[i] != '\n' && buf[i] != '\0')
    {
      if (buf[i] < '0' || buf[i] > '9')
	z = 1997;
      i++;
    }
  if (z == 1997)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  return (0);
}

int	check_invalid_line(int line)
{
  int	l;
  char	*buf;

  l = line + 10;;
  while (l >= line || l < 0)
    {
      if ((buf = get_line(1)) == NULL)
	return (1000000);
      while ((check_wrong_char(buf)) != 0)
	{
	  if ((buf = get_line(1)) == NULL)
	    return (1000000);
	}
      l = my_getnbr(buf) - 1;
      free(buf);
      if (l >= line || l == -1)
	my_putstr("Error: this line is out of range\n");
      else if (l < 0)
	my_putstr("Error: invalid input (positive number expected)\n");
    }
  return (l);
}

int	check_invalid_match(int match, int line, char **map)
{
  t_check	var;

  var.l = match + 10;
  while (var.l > match || var.l <= 0)
    {
      if ((var.buf = get_line(2)) == NULL)
	return (1000000);
      if ((var.check = shorcut2(var.buf)) == 1100000 || var.check == 1000000)
	return (var.check);
      var.l = my_getnbr(var.buf);
      var.nope = number_of_stick(map[line]);
      if (var.l > var.nope && var.l <= match)
	{
	  var.l = shorcut(var.l, match);
	  free(var.buf);
	  return (1100000);
	}
      if ((print_error_message(var.l, match)) == 999999)
	return (1100000);
    }
  return (var.l);
}

int	shorcut(int l, int match)
{
  l = match + 10;
  my_putstr("Error: not enough matches on this line\n");
  return (l);
}

int	shorcut2(char *buf)
{
  int	a;

  while ((a = check_wrong_char(buf)) != 0)
    {
      if (a == 1)
	return (1100000);
      if ((buf = get_line(2)) == NULL)
	return (1000000);
    }
  return (0);
}
