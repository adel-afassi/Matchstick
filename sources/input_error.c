/*
** input_error.c for  in /home/adel/delivery/CPE_2016_matchstick/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 16:48:22 2017 John Doe
** Last update Wed Feb 22 23:35:43 2017 John Doe
*/

#include "my.h"

int	print_error_message(int l, int matche)
{
  if (l > matche || l <= 0)
    {
      if (l == 0)
	{
	  my_putstr("Error: you have to remove at least one match\n");
	  return (999999);
	}
      else if (l < 0)
	{
	  my_putstr("Error: invalid input (positive number expected)\n");
	  return (999999);
	}
      else
	{
	  my_putstr("Error: you cannot remove more than ");
	  my_putnbr(matche);
	  my_putstr(" matches per turn\n");
	  return (999999);
	}
    }
  return (0);
}

void	print_prompt_player(int matche, int line_seizure)
{
  my_putstr("Player removed ");
  my_putnbr(matche);
  my_putstr(" match(es) from line ");
  my_putnbr(line_seizure + 1);
  my_putchar('\n');
}

void	print_prompt_ia(int matche, int line_seizure)
{
  my_putstr("AI removed ");
  my_putnbr(matche);
  my_putstr(" match(es) from line ");
  my_putnbr(line_seizure + 1);
  my_putchar('\n');
}
