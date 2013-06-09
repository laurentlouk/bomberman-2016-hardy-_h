//
// Primitive.cpp for bbman in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 14 19:23:44 2013 laurent loukopoulos
// Last update Sat Jun  1 01:26:54 2013 laurent loukopoulos
//

#include	"../include/Primitive.hpp"

namespace	Primitive
{
  void	Triangle::initialize(void)
  {

  }

  void	Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {

  }

  /* ----------- triangle --------------*/

  void	Triangle::draw(void)
  {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.50f, 0.75f);

    glVertex3f(0.0f, 150.0f, 0.0f);
    glVertex3f(-150.0f, 0.0f, 0.0f);
    glVertex3f(150.0f, 0.0f, 0.0f);

    glEnd();
  }

  /* ----------- ractangle --------------*/

  void	Rectangle::initialize(void)
  {
    this->sol_ = gdl::Image::load("photo/grass.jpg");
    this->map_.initialize();
  }

  void	Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {

  }

  void	Rectangle::draw(void)
  {
    int		i=0;
    int		j=0;
    float	x=150.0f * this->map_.x;
    float       y=150.0f * this->map_.y;

    /*    while (this->map_.y != j)
	  {
	  i = 0;
	  x = 150.0f * this->map_.x;
	  while (this->map_.x != i)
	  {
	  create(x, y);
	  x -= 275.0f;
	  i++;
	  }
	  y -= 275.0f;
	  j++;
	  }*/

    create(this->map_.x, this->map_.y);
  }

  void	Rectangle::create(float x, float y)
  {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    //glTranslatef(x, 0.0f, y);

    this->sol_.bind();

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(150.0f * x, 0.0f, 150.0f * y);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(150.0f * x, 0.0f, -150.0f * y);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-150.0f * x, 0.0f, -150.0f * y);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-150.0f * x, 0.0f, 150.0f * y);

    glEnd();

    glPopMatrix();
  }
}
