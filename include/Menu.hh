//
// MyGame2.hh for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Wed May 22 16:52:11 2013 laurent loukopoulos
// Last update Sat Jun  8 05:30:31 2013 laurent loukopoulos
//

#ifndef		__MENU_HH__
#define		__MENU_HH__

#include	<cstdlib>
#include	<GL/glu.h>
#include	<GL/gl.h>
#include	<list>
#include	<iostream>
#include	<SFML/Audio.hpp>

#include	"Game.hpp"
#include	"AObject.hh"
#include	"Vector3f.hpp"
#include	"Camera_Menu.hh"
#include	"Image.hpp"
#include	"Model.hpp"

#include	"Primitive.hpp"
#include	"Bomberman.hpp"

class		Menu : virtual public gdl::Game
{
public:
  Menu();
  virtual ~Menu();

  void initialize();
  void update();
  void draw();
  void unload();

private:
  Camera_Menu		camera_;
  std::list<AObject*>	objects_;
  sf::Music		music_;
};

#endif
