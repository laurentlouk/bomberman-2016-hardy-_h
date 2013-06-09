//
// Fire.cpp for bomber in /home/hardy-_h//Epitech /tek2_2013/C++/bomberman/bomber/loukop_l
// 
// Made by hugo hardy-dessources
// Login   <hardy-_h@epitech.net>
// 
// Started on  Tue Jun  4 17:30:57 2013 hugo hardy-dessources
// Last update Fri Jun  7 18:31:32 2013 hugo hardy-dessources
//

#include "../include/Bomberman.hpp"

namespace	Model
{

  void		Fire::init(float coord_expl_x, float coord_expl_y, int power)
  {
    this->texture_ = gdl::Image::load("photo/fire.jpg");
    this->slide = 150.0f;
    this->coord_bomb_x = coord_expl_x;
    this->coord_bomb_y = coord_expl_y;
    this->power_ = power;
    this->fire_on = false;
    this->fire_off = false;
    this->map_.initialize();
  }

  void		Fire::update()
  {
    this->clock_.update();
    if(this->clock_.getTotalElapsedTime() > Fire::lifetime_bomb && !this->fire_on)
      {
	this->fire_off = false;
	this->fire_on = true;
	this->clock_.pause();
	this->clock_.reset();
      }
    if(this->clock_.getTotalElapsedTime() > Fire::lifetime && !this->fire_off)
      {
	this->fire_on = false;
	this->fire_off = true;
	this->clock_.pause();
	this->clock_.reset();
      }
  }

  void		Fire::draw(void)
  {
    int		i = 1;
    bool	s1 = true;

    while (this->power_ + 1 != i)
      {
	position_x_y(this->coord_bomb_x, this->coord_bomb_y);
	if (this->map_.tab[this->coord_bomb_x - 1][this->coord_bomb_y] != 1)
	  position_x_y(this->coord_bomb_x - i, this->coord_bomb_y);
	if (this->map_.tab[this->coord_bomb_x + 1][this->coord_bomb_y] != 1)
	  position_x_y(this->coord_bomb_x + i, this->coord_bomb_y);
	if (this->map_.tab[this->coord_bomb_x][this->coord_bomb_y + 1] != 1)
	  position_x_y(this->coord_bomb_x, this->coord_bomb_y + i);
	if (this->map_.tab[this->coord_bomb_x][this->coord_bomb_y - 1] != 1)
	  position_x_y(this->coord_bomb_x, this->coord_bomb_y - i);
	i++;
      }
  }

  void		Fire::create(float x, float y)
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

  void		Fire::position_x_y(float x, float y)
  {
    x = (-x + (this->map_.x / 2));
    y = (-y + (this->map_.y / 2));
    create((-300.0f * (x)) + 150, (300.0f * (y)) - 150);
  }
}
