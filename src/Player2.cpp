//
// Player2.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Sun Jun  2 19:02:24 2013 laurent loukopoulos
// Last update Sat Jun  8 21:28:03 2013 laurent loukopoulos
//

#include	"../include/Bomberman.hpp"

namespace	Model
{
  void		Bomberman::create_player2(void)
  {
    int		i = 0;
    int		j = 0;

    while (i != this->map_.x)
      {
	j = 0;
	while (j != this->map_.y)
	  {
	    if (this->map_.tab[i][j] == 4)
	      position2_x_y(i, j);
	    j++;
	  }
	i++;
      }

    this->model2_ = gdl::Model::load("assets/marvin.fbx");
    this->life2 = 1;

    this->keyboard2[gdl::Keys::Z] = &Bomberman::Z;
    this->keyboard2[gdl::Keys::S] = &Bomberman::S;
    this->keyboard2[gdl::Keys::Q] = &Bomberman::Q;
    this->keyboard2[gdl::Keys::D] = &Bomberman::D;
  }

  void		Bomberman::Z()
  {
    int		x = sx2 - 0.5f;
    int		y = sy2;

    this->model2_.play("Run");
    this->rot2_x = -90;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 8)
      this->move2_x -= this->speed2;
  }

  void		Bomberman::S()
  {
    int		x = sx2 + 0.5f;
    int		y = sy2;

    this->model2_.play("Run");
    this->rot2_x = 90;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 8)
      this->move2_x += this->speed2;
  }

  void		Bomberman::Q()
  {
    int		x = sx2;
    int		y = sy2 - 0.5f;

    this->model2_.play("Run");
    this->rot2_x = 0;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 8)
      this->move2_y += this->speed2;
  }

  void		Bomberman::D()
  {
    int		x = sx2;
    int		y = sy2 + 0.5f;

    this->model2_.play("Run");
    this->rot2_x = 180;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 8)
      this->move2_y -= this->speed2;
  }

  void		Bomberman::game_player2(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    sx2 = -((((-this->move2_x) / 150 ) - this->map_.x) / 2);
    sy2 = ((((-this->move2_y) / 150 ) + this->map_.y) / 2);

    this->movement2 = false;
    this->it2 = keyboard2.begin();
    this->end2 = keyboard2.end();

    this->model2_.update(gameClock);

    model2_.set_default_model_color(gdl::Color(255,255,0));
    model2_.cut_animation(this->model2_, "Take 001", 40, 60, "Run");
    model2_.cut_animation(this->model2_, "Take 001", 0, 0, "Stop");

    while (it2 != end2)
      {
	if (input.isKeyDown((*it2).first) == true)
	  {
	    this->movement2 = true;
	    (this->*(*it2).second)();
	  }
	++it2;
      }

    if (movement2 == false)
      this->model2_.play("Stop");
  }

  void		Bomberman::draw_player2(void)
  {
    //player2
    glPushMatrix();

    glTranslatef(this->move2_x, 0.0f, this->move2_y);
    glRotatef(this->rot2_x, 0, 1, 0);

    this->model2_.draw();

    glPopMatrix();
  }

  void		Bomberman::position2_x_y(float x, float y)
  {
    sx2 = x;
    sy2 = y;

    x = x * 2;
    y = y * 2;

    x = (this->map_.x + (-x));
    y = (this->map_.y + (-y));

    this->move2_x = -((x * 150.0f) - 150);
    this->move2_y =  ((y * 150.0f) - 150);
  }
}
