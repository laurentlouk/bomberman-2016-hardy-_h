//
// Camera.cpp for bbman in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Fri May 17 03:21:44 2013 laurent loukopoulos
// Last update Sat Jun  8 05:56:55 2013 laurent loukopoulos
//

#include	"../include/Camera.hh"
#include	<iostream>

Camera::Camera(void) : position_(3500.0f, 3500.0f, 3500.0f), rotation_(0.0f, 0.0f, 0.0f)
{

}

Camera::~Camera(void)
{

}

void	Camera::initialize(void)
{
  this->zoom = 70.0f;
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

void	Camera::update(gdl::GameClock const & gameClock, gdl::Input & input, float x, float y)
{
  if (input.isKeyDown(gdl::Keys::P) == true && position_.y < 9000.0f)
    position_.y += 90.0f;
  if (input.isKeyDown(gdl::Keys::M) == true && position_.y > 980.0f)
    position_.y -= 90.0f;
  /*  if (input.isKeyDown(gdl::Keys::O) == true && this->zoom < 100.0f)
      this->zoom += 1.0f;
      if (input.isKeyDown(gdl::Keys::L) == true && this->zoom > 40.0f)
      this->zoom -= 1.0f;*/

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(this->zoom, 1200.0f/900.0f, 1.0f, 100000.0f);
  gluLookAt(position_.x, position_.y, position_.z, rotation_.x, rotation_.y, rotation_.z, 0.0f, 1.0f, 0.0f);
}
