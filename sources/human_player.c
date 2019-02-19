/*
** human_player.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Feb 25 19:22:28 2017 John Doe
** Last update Mon Feb 27 14:21:38 2017 John Doe
*/

#include "my.h"

void	decale_space(char **map, int matche, int line_seizure, int size)
{
  int	copy;

  copy = 0;
  while (copy < matche)
    {
      map[line_seizure][size--] = ' ';
      copy++;
    }
}

char	*get_line(int i)
{
  char	*buf;

  if (i == 1)
    my_putstr("Line: ");
  else
    my_putstr("Matches: ");
  if ((buf = get_next_line(0)) == NULL)
    {
      my_putstr("\n");
      return (NULL);
    }
  return (buf);
}

char	**human_player(char **map, int line, int match)
{
  int	line_seizure;
  int	matche;

  matche = 1100000;
  my_putstr("\nYour turn:\n");
  while (matche == 1100000)
    {
      if ((line_seizure = check_invalid_line(line)) == 1000000)
	return (NULL);
      if ((matche = check_invalid_match(match, line_seizure, map)) == 1000000)
	return (NULL);
    }
  shorcut3_player(line_seizure, matche, map);
  return (map);
}

void	shorcut3_player(int line_seizure, int matche, char ** map)
{
  int	size;

  size = my_strlen(map[line_seizure]) - 1;
  while (map[line_seizure][size] == ' ')
    size--;
  decale_space(map, matche, line_seizure, size);
  print_prompt_player(matche, line_seizure);
}

void	shorcut3_ia(int line_seizure, int matche, char ** map)
{
  int	size;

  size = my_strlen(map[line_seizure]) - 1;
  while (map[line_seizure][size] == ' ')
    size--;
  decale_space(map, matche, line_seizure, size);
  print_prompt_ia(matche, line_seizure);
}
