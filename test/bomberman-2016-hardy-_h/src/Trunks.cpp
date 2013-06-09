//
// Trunks.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Thu Jun  6 01:02:41 2013 laurent loukopoulos
// Last update Sat Jun  8 02:38:25 2013 laurent loukopoulos
//

#include	"../include/Bomberman.hpp"
#include	<iostream>

namespace       Model
{
  void		Trunks::initialize(void)
  {
    this->texture_ = gdl::Image::load("photo/Trunks.jpg");
    this->map_.initialize();
    this->z = 150.0f;
  }

  void		Trunks::remove(int x, int y)
  {
    this->map_.tab[x][y] = 0;
  }

  void		Trunks::draw(void)
  {
    int		i = 0;
    int		j = 0;

    while (i != this->map_.x)
      {
	j = 0;
	while (j != this->map_.y)
	  {
	    if (this->map_.tab[i][j] == 2)
	      {
		position_x_y(i,j);
	      }
	    j++;
	  }
	i++;
      }
  }

  void	Trunks::create(float x, float y)
  {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glTranslatef(x, this->z, y);

    this->texture_.bind();

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(150.0f, 150.0f, 150.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(150.0f, 150.0f, -150.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-150.0f, 150.0f, -150.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-150.0f, 150.0f, 150.0f);

    /// Vertex superieur gauche
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(150.0f, -150.0f, 150.0f);
    /// Vertex inferieur gauche
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(150.0f, -150.0f, -150.0f);
    /// Vertex inferieur droit
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(150.0f, 150.0f, -150.0f);
    /// Vertex superieur droit
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(150.0f, 150.0f, 150.0f);

    glTexCoord2f(0.0f, 0.0f);
    /// Vertex superieur gauche
    glVertex3f(-150.0f, -150.0f, 150.0f);
    /// Vertex inferieur gauche
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-150.0f, -150.0f, -150.0f);
    /// Vertex inferieur droit
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(150.0f, -150.0f, -150.0f);
    /// Vertex superieur droit
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(150.0f, -150.0f, 150.0f);

    glTexCoord2f(0.0f, 0.0f);
    /// Vertex superieur gauche
    glVertex3f(-150.0f, 150.0f, 150.0f);
    /// Vertex inferieur gauche
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-150.0f, 150.0f, -150.0f);
    /// Vertex inferieur droit
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-150.0f, -150.0f, -150.0f);
    /// Vertex superieur droit
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-150.0f, -150.0f, 150.0f);

    glTexCoord2f(0.0f, 0.0f);
    /// Vertex superieur gauche
    glVertex3f(150.0f, 150.0f, -150.0f);
    /// Vertex inferieur gauche
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(150.0f, -150.0f, -150.0f);
    /// Vertex inferieur droit
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-150.0f, -150.0f, -150.0f);
    /// Vertex superieur droit
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-150.0f, 150.0f, -150.0f);

    glTexCoord2f(0.0f, 0.0f);
    /// Vertex superieur gauche
    glVertex3f(150.0f, -150.0f, 150.0f);
    /// Vertex inferieur gauche
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(150.0f, 150.0f, 150.0f);
    /// Vertex inferieur droit
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-150.0f, 150.0f, 150.0f);
    /// Vertex superieur droit
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-150.0f, -150.0f, 150.0f);
    
    glEnd();

    glPopMatrix();
  }

  void	Trunks::position_x_y(float x, float y)
  {
    x = (-x + (this->map_.x / 2));
    y = (-y + (this->map_.y / 2));
    create((-300.0f * (x)) + 150, (300.0f * (y)) - 150);
  }

}

