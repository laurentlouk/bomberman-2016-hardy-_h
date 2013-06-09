//
// Primitive.hpp for bbman in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 14 19:13:02 2013 laurent loukopoulos
// Last update Mon Jun  3 20:18:32 2013 laurent loukopoulos
//

#ifndef		__PRIMITIVE_HH__
#define		__PRIMITIVE_HH__

#include	<iostream>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<map>

#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"AObject.hh"
#include	"Object.hpp"
#include	"MyPause.hh"
#include	"Map.hpp"

namespace	Primitive
{
  class		Triangle : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
  private:
    gdl::Image	sol_;
  };

  class		Rectangle : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
    void	create(float, float);
  private:
    gdl::Image	sol_;
    Map		map_;

    float	x;
    float	y;

  };

  class		BGMenu : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
    void  setNbrMenu(int);
    void  Up(gdl::GameClock const &);
    void  Down(gdl::GameClock const &);
    void  Left(gdl::GameClock const &);
    void  Right(gdl::GameClock const &);
    void  sendParam(void);
    bool  is_readable(const std::string &);

  private:
    gdl::Image	Menu_;
    float	myClock;
    int   nbrMenuTotal;
    int   nbrMenu;
    int   nbrMenuPlayer;
    int   check;
    MyPause pause_;

    std::map<int, gdl::Image> nbrNameMenu;
    std::map<int, gdl::Image>::const_iterator it;
    std::map<int, gdl::Image>::const_iterator end;

    std::map<gdl::Keys::Key, void (BGMenu::*)(gdl::GameClock const &)> keyMenu;
    std::map<gdl::Keys::Key, void (BGMenu::*)(gdl::GameClock const &)>::const_iterator itMenu;
    std::map<gdl::Keys::Key, void (BGMenu::*)(gdl::GameClock const &)>::const_iterator endMenu;
  };
}

#endif
