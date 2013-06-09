//
// Camera_Menu.hh for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Wed May 22 17:46:34 2013 laurent loukopoulos
// Last update Wed May 22 17:47:37 2013 laurent loukopoulos
//

#ifndef		__CAMERA_MENU_HH__
#define		__CAMERA_MENU_HH__

#include	<GL/glu.h>
#include	<GL/gl.h>

#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Vector3f.hpp"
#include	"Window.hpp"

class		Camera_Menu
{
public:
  Camera_Menu();
  ~Camera_Menu();

  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &, float x, float y);

private:
  Vector3f	position_;
  Vector3f	rotation_;
  float		rot;
};

#endif
