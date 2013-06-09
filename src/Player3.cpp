//
// Player3.cpp for bbman in /home/loukop_l//loukop_l/bomberman-2016-hardy-_h
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Sat Jun  8 23:48:28 2013 laurent loukopoulos
// Last update Sat Jun  8 23:49:24 2013 laurent loukopoulos
//

#include "../include/Bomberman.hpp"
#include <iostream>

namespace Model
{
  void          Bomberman::init_Ia(void)
  {
    int         i = 0;
    int         j = 0;

    while (i != this->map_.x)
      {
        j = 0;
        while (j != this->map_.y)
          {
            if (this->map_.tab[i][j] == 4)
              {
                positionia_x_y(i, j);
              }
            j++;
          }
        i++;
      }
    this->i_a1 = gdl::Model::load("assets/marvin.fbx");
  }

  float         Bomberman::up_Ia()
  {
    int         x = sx3 - 0.5f;
    int         y = sy3;

    this->rotIa_x = - 90;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2)
      this->posIa_x = this->posIa_x - 20;
    return (this->posIa_x);
  }

  float         Bomberman::down_Ia()
  {
    int         x = sx3 + 0.5f;
    int         y = sy3;

    this->rotIa_x = 90;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2)
      this->posIa_x = this->posIa_x + 20;
    return (this->posIa_x);
  }

  float         Bomberman::left_Ia()
  {
    int         x = sx3;
    int         y = sy3 - 0.5f;


    this->rotIa_x = 0;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2)
      this->posIa_y = this->posIa_y + 20;
    return (this->posIa_y);
  }

  float         Bomberman::right_Ia()
  {
    int         x = sx3;
    int         y = sy3 + 0.5f;

    this->rotIa_x = 180;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2)
      this->posIa_y = this->posIa_y - 20;
    return (this->posIa_y);
  }

  void          Bomberman::updt_Ia()
  {
    int         i;

    srand (time(NULL));
    this->check_pos_x =  ((((-this->posIa_x) / 150 ) + this->map_.x) / 2);
    this->check_pos_y = -((((-this->posIa_y) / 150 ) - this->map_.y) / 2);
    sx3 = -((((-this->posIa_x) / 150 ) - this->map_.x) / 2);
    sy3 = ((((-this->posIa_y) / 150 ) + this->map_.y) / 2);
    int         iax = sx3;
    int         iay = sy3;

    i = rand() % 4 + 1;
    if (i == 1)
      up_Ia();
    if (i == 2)
      down_Ia();
    if (i == 3)
      left_Ia();
    if (i == 4)
      right_Ia();
  }

  void          Bomberman::drw_Ia(void)
  {
    glPushMatrix();
    glTranslatef(this->posIa_x, 0.0f, this->posIa_y);
    glRotatef(this->rotIa_x, 0, 1, 0);

    this->i_a1.draw();

    glPopMatrix();
  }

  void          Bomberman::positionia_x_y(float x, float y)
  {
    sx3 = x;
    sy3 = y;

    x = x * 2;
    y = y * 2;

    x = (this->map_.x + (-x));
    y = (this->map_.y + (-y));

    this->posIa_x = -((x * 150.0f) - 150);
    this->posIa_y =  ((y * 150.0f) - 150);
  }
}
