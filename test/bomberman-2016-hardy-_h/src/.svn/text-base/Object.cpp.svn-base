//
// Object.cpp for bbman in /home/loukop_l//bomberman/bb/src
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Mon May 20 01:27:28 2013 laurent loukopoulos
// Last update Sat Jun  8 17:51:33 2013 laurent loukopoulos
//

#include	"../include/Object.hpp"

namespace	Object
{
  void		Cube::initialize(void)
  {
    this->texture_ = gdl::Image::load("photo/wall");
    this->slide = 150.0f;
    this->map_.initialize();
  }

  void		Cube::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {

  }

  void		Cube::draw(void)
  {
    int		i = 0;
    int		j = 0;

    while (i != this->map_.x)
      {
	j = 0;
	while (j != this->map_.y)
	  {
	    if (this->map_.tab[i][j] == 1)
	      position_x_y(i, j);
	    j++;
	  }
	i++;
      }
  }

  void	Cube::create(float x, float y)
  {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glTranslatef(x, this->slide, y);

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

  void	Cube::position_x_y(float x, float y)
  {
    x = (-x + (this->map_.x / 2));
    y = (-y + (this->map_.y / 2));
    create((-300.0f * (x)) + 150, (300.0f * (y)) - 150);
  }

  void Pyramide::initialize(void)
  {
  }
  void Pyramide::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->rotation_.y = ((int)rotation_.y + 1) % 360;
  }
  void Pyramide::draw(void)
  {
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -900.0f);
    ////////////////////////////////////////////////////////////////////////////////
    /// Rotation autour de l’axe Y
    ////////////////////////////////////////////////////////////////////////////////
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    ////////////////////////////////////////////////////////////////////////////////
    /// Ouverture d’un contexte de rendu
    ////////////////////////////////////////////////////////////////////////////////
    glBegin(GL_TRIANGLES);
    ////////////////////////////////////////////////////////////////////////////////
    /// Dessin des vertices
    ////////////////////////////////////////////////////////////////////////////////
    glColor3f(1.0f, 1.0f, 1.0f);
    /// Vertex haut : B
    glVertex3f(0.0f, -150.0f, -150.0f);
    /// Vertex inferieur gauche : C
    glVertex3f(-150.0f, -150.0f, 150.0f);
    /// Vertex inferieur droit : D
    glVertex3f(150.0f, -150.0f, 150.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    /// Vertex haut : A
    glVertex3f(0.0f, 150.0f, 0.0f);
    /// Vertex inferieur gauche : C
    glVertex3f(-150.0f, -150.0f, 150.0f);
    /// Vertex inferieur droit : D
    glVertex3f(150.0f, -150.0f, 150.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    /// Vertex haut : A
    glVertex3f(0.0f, 150.0f, 0.0f);
    /// Vertex inferieur gauche : B
    glVertex3f(0.0f, -150.0f, -150.0f);
    /// Vertex inferieur droit : C
    glVertex3f(-150.0f, -150.0f, 150.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    /// Vertex haut : A
    glVertex3f(0.0f, 150.0f, 0.0f);
    /// Vertex inferieur gauche : D
    glVertex3f(150.0f, -150.0f, 150.0f);
    /// Vertex inferieur droit : B
    glVertex3f(0.0f, -150.0f, -150.0f);

    glEnd();
  }
}
