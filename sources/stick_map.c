/*
** stick_map.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 20 16:51:09 2017 John Doe
** Last update Sat Feb 25 21:34:12 2017 John Doe
*/

#include "my.h"

int	last_line_size(int line)
{
  int	i;
  int	counter;

  i = 1;
  counter = 1;
  while (counter < line)
    {
      i = i + 2;
      counter++;
    }
  return (i);
}

char	**tab_malloc(int line)
{
  int	size;
  char	**map;
  int	i;

  i = 0;
  size = 3;
  if ((map = tmalloc(line + 1)) == NULL)
    return (NULL);
  while (i < line)
    {
      if ((map[i] = xmalloc(size)) == NULL)
	return (NULL);
      size = size + 2;
      i++;
    }
  map[i] = NULL;
  return (map);
}

char	*put_stick(char *map, int stick)
{
  int	i;

  i = 0;
  while (i < stick)
    map[i++] = '|';
  map[i] = '\0';
  return (map);
}

char	**put_stick_map(int line)
{
  char	**map;
  int	i;
  int	z;

  z = 1;
  i = 0;
  if ((map = tab_malloc(line)) == NULL)
    return (NULL);
  while (i < line)
    {
      map[i] = put_stick(map[i], z);
      z = z + 2;
      i++;
    }
  i = 0;
  print_map(map);
  return (map);
}
