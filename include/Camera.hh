//
// Camera.hh for bbman in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 14 17:59:11 2013 laurent loukopoulos
// Last update Sat Jun  8 05:54:51 2013 laurent loukopoulos
//

#ifndef		__CAMERA_HH__
#define		__CAMERA_HH__

#include	<GL/glu.h>
#include	<GL/gl.h>

#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Vector3f.hpp"
#include	"Window.hpp"

class		Camera
{
public:
  Camera();
  ~Camera();

  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &, float x, float y);

private:
  Vector3f	position_;
  Vector3f	rotation_;
  float		rot;
  float		zoom;
};

#endif
