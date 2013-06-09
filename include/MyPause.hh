//
// MyClock.hh for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 28 14:53:04 2013 laurent loukopoulos
// Last update Sat Jun  8 17:29:31 2013 laurent loukopoulos
//

#ifndef		__MYCLOCK_HH__
#define		__MYCLOCK_HH__

#include	<iostream>
#include	<string>

#include	"GameClock.hpp"
#include	"Clock.hpp"

class		MyPause
{
public:
  MyPause();
  ~MyPause();
  void		pause(gdl::GameClock const & gameClock, float countDown);
  bool		pauseall;
private:
  float		saveClock;
};

#endif
