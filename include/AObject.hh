//
// AObject.hh for bbman in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Thu May 16 21:10:43 2013 laurent loukopoulos
// Last update Fri May 24 14:50:04 2013 laurent loukopoulos
//

#ifndef         __AOBJECT_HH__
#define         __AOBJECT_HH__

#include        "Image.hpp"
#include        "GameClock.hpp"
#include        "Input.hpp"
#include        "Vector3f.hpp"

class   AObject
{
public:
  AObject() : _position(0.0f, 0.0f, 0.0f), _rotation(0.0f, 0.0f, 0.0f)
  {

  }
  virtual void  initialize(void) = 0;
  virtual void  update(gdl::GameClock const &, gdl::Input&) = 0;
  virtual void  draw() = 0;

protected:
  Vector3f      _position;
  Vector3f      _rotation;
};

#endif
