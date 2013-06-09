//
// Menu.hpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 21 19:15:22 2013 laurent loukopoulos
// Last update Tue May 21 19:20:33 2013 laurent loukopoulos
//

#ifndef		__MENU_HPP__
#define		__MENU_HPP__

#include	<GL/gl.h>
#include	<GL/glu.h>

#include	"Image.hpp"
#include	"GameClock.hpp"
#include	"AObject.hpp"
#include	"Vector3f.hpp"

namespace	Object
{
  class		Menu : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
  };
}

#endif
