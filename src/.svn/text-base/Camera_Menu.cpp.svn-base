//
// Camera_Menu.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/src
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Wed May 22 17:29:04 2013 laurent loukopoulos
// Last update Thu May 23 11:05:06 2013 laurent loukopoulos
//

#include	"../include/Camera_Menu.hh"
#include	<iostream>

Camera_Menu::Camera_Menu(void) : position_(0.0f, 0.0f, 900.0f), rotation_(0.0f, 0.0f, 0.0f)
{

}

Camera_Menu::~Camera_Menu(void)
{

}

void	Camera_Menu::initialize(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 1200.0f/900.0f, 1.0f, 100000.0f);
  gluLookAt(position_.x, position_.y, position_.z,
	    rotation_.x, rotation_.y, rotation_.z,
	    0.0f, 1.0f, 0.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void	Camera_Menu::update(gdl::GameClock const & gameClock, gdl::Input & input, float x, float y)
{
  if (input.isKeyDown(gdl::Keys::P) == true)
    position_.y += 90.0f;
  if (input.isKeyDown(gdl::Keys::M) == true)
    position_.y -= 90.0f;
  if (input.isKeyDown(gdl::Keys::O) == true)
    position_.z += 100.0f;
  if (input.isKeyDown(gdl::Keys::L) == true)
    position_.z -= 100.0f;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 1200.0f/900.0f, 1.0f, 100000.0f);
  gluLookAt(position_.x, position_.y, position_.z, rotation_.x, rotation_.y, rotation_.z, 0.0f, 1.0f, 0.0f);
}
