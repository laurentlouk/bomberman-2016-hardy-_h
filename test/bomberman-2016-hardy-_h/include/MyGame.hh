//
// MyGame.hh for bbùan in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 14 15:36:58 2013 laurent loukopoulos
// Last update Sat Jun  8 17:28:46 2013 laurent loukopoulos
//

#ifndef		__MYGAME_HH__
#define		__MYGAME_HH__

#include	<cstdlib>
#include	<GL/glu.h>
#include	<GL/gl.h>
#include	<list>
#include	<iostream>
#include	<SFML/Audio.hpp>

#include	"Game.hpp"
#include	"AObject.hh"
#include	"Vector3f.hpp"
#include	"Camera.hh"
#include	"Image.hpp"
#include	"Model.hpp"
#include	"MyPause.hh"

#include	"Primitive.hpp"
#include	"Bomberman.hpp"
#include	"Map.hpp"

class		MyGame : virtual public gdl::Game
{
public:
  MyGame();
  virtual ~MyGame();

  void initialize();
  void update();
  void draw();
  void unload();

private:
  Camera		camera_;
  std::list<AObject*>	objects_;
  sf::Music		music_;
  Map			map_;
  MyPause		pause_;
};

#endif
