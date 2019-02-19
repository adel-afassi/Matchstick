/*
** check_fonction.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 20:04:14 2017 John Doe
** Last update Tue Feb 21 20:05:54 2017 John Doe
*/

#include "my.h"

char	*xmalloc(int size)
{
  char	*str;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (NULL);
    }
  return (str);
}

char	**tmalloc(int size)
{
  char	**str;

  if ((str = malloc(sizeof(char *) * size)) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (NULL);
    }
  return (str);
}
