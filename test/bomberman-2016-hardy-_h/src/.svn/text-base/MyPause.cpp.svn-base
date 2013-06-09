//
// MyClock.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 28 15:06:14 2013 laurent loukopoulos
// Last update Sat Jun  8 17:24:28 2013 laurent loukopoulos
//

#include	"../include/MyPause.hh"

MyPause::MyPause()
{
  this->saveClock = 0;
}

MyPause::~MyPause()
{

}

void		MyPause::pause(gdl::GameClock const & gameClock, float countDown)
{
  this->saveClock = gameClock.getTotalGameTime() + countDown;
  while (gameClock.getTotalGameTime() < this->saveClock)
    {

    }
}
