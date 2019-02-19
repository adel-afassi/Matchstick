/*
** print_game_board.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 20 18:15:33 2017 John Doe
** Last update Tue Feb 21 20:16:28 2017 John Doe
*/

#include "my.h"

void	print_space(int space)
{
  int	counter;

  counter = 0;
  while (counter < space)
    {
      my_putchar(' ');
      counter++;
    }
}

void	print_stars(int nb)
{
  int	counter;

  counter = 0;
  while (counter < nb)
    {
      my_putchar('*');
      counter++;
    }
  my_putchar('\n');
}

void	print_map(char **map)
{
  int	i;
  int	counter;
  int	z;
  int	a;

  a = 0;
  counter = 0;
  while (map[counter])
    counter++;
  i = my_strlen(map[counter - 1]);
  print_stars(i + 2);
  z = (i - 1) / 2;
  while (map[a] != NULL)
    {
      my_putchar('*');
      print_space(z);
      my_putstr(map[a++]);
      print_space(z);
      my_putstr("*\n");
      z--;
    }
  print_stars(i + 2);
}
