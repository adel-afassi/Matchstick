/*
** my_getnbr.c for  in /home/adel/delivery/CPE_2016_matchstick
**
** Made by adel
** Login   <adel.afassi@epitech.eu>
**
** Started on  Mon Feb 20 11:49:18 2017 adel
** Last update Tue Feb 21 20:16:03 2017 John Doe
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	neg;
  int	nb;

  nb = 0;
  i = 0;
  neg = 0;
  while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
    i = i + 1;
  if (i != 0)
    {
      if (str[i - 1] != '\0' && str[i - 1] == '-')
	neg = 1;
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - 48);
      i = i + 1;
    }
  if (neg == 1)
    nb = nb * -1;
  return (nb);
}

int	my_getcharnbr(char c)
{
  int	nb;

  nb = 0;
  nb = nb * 10 + (c - 48);
  return (nb);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
