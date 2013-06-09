//
// Explosion.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/src
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Thu Jun  6 23:29:50 2013 laurent loukopoulos
// Last update Fri Jun  7 12:30:40 2013 laurent loukopoulos
//

#include	"../include/Bomberman.hpp"

void		Bomberman::explosion(int x, int y, int power)
{
  int		i = 0;

  this->map_.tab[x][y] = 9;
  /* check le players */

  while (power != i)
    {
      if (this->map_.tab[x - i][y] == 2;)
	{
	  this->trunks_.remove(x - i, y); // check it by the way
	}
      this->map_.tab[x - i][y] == 9;
      i++;
    }

  i = 0;
  while (power != i)
    {
      if (this->map_.tab[x + i][y] == 2;)
	{
	  this->trunks_.remove(x + i, y); // check it by the way
	}
      this->map_.tab[x + i][y] == 9;
      i++;
    }

  i = 0;
  while (power != i)
    {
      if (this->map_.tab[x][y - i] == 2;)
	{
	  this->trunks_.remove(x, y - i); // check it by the way
	}
      this->map_.tab[x][y - i] == 9;
      i++;
    }

  i = 0;
  while (power != i)
    {
      if (this->map_.tab[x][y + i] == 2;)
	{
	  this->trunks_.remove(x, y + i); // check it by the way
	}
      this->map_.tab[x][y + i] == 9;
      i++;
    }
}

void		Bomberman::normal_again(void)
{
  //time clock
  /* parcourir tableau si 9 alors metre 0 */
}
