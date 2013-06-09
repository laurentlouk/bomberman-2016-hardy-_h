//
// Player1.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Sat Jun  1 17:17:45 2013 laurent loukopoulos
// Last update Sat Jun  8 21:25:20 2013 laurent loukopoulos
//

#include	"../include/Bomberman.hpp"

namespace	Model
{
  void		Bomberman::create_player1(void)
  {
    int		i = 0;
    int		j = 0;

    while (i != this->map_.x)
      {
	j = 0;
	while (j != this->map_.y)
	  {
	    if (this->map_.tab[i][j] == 3)
	      position_x_y(i, j);
	    j++;
	  }
	i++;
      }

    this->model_ = gdl::Model::load("assets/marvin.fbx");
    this->life1 = 1;
    this->keyboard[gdl::Keys::Up] = &Bomberman::Up;
    this->keyboard[gdl::Keys::Down] = &Bomberman::Down;
    this->keyboard[gdl::Keys::Left] = &Bomberman::Left;
    this->keyboard[gdl::Keys::Right] = &Bomberman::Right;
  }

  void		Bomberman::Up()
  {
    int		x = sx - 0.5f;
    int		y = sy;

    this->model_.play("Run");
    this->rot_x = -90;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 9)
      this->move_x -= this->speed;
  }

  void		Bomberman::Down()
  {
    int		x = sx + 0.5f;
    int		y = sy;

    this->model_.play("Run");
    this->rot_x = 90;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 9)
      this->move_x += this->speed;
  }

  void		Bomberman::Left()
  {
    int		x = sx;
    int		y = sy - 0.5f;

    this->model_.play("Run");
    this->rot_x = 0;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 9)
      this->move_y += this->speed;
  }

  void		Bomberman::Right()
  {
    int		x = sx;
    int		y = sy + 0.5f;

    this->model_.play("Run");
    this->rot_x = 180;
    if (this->map_.tab[x][y] != 1 && this->map_.tab[x][y] != 2 && this->map_.tab[x][y] != 9)
      this->move_y -= this->speed;
  }

  void		Bomberman::game_player1(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    sx = -((((-this->move_x) / 150 ) - this->map_.x) / 2);
    sy = ((((-this->move_y) / 150 ) + this->map_.y) / 2);

    this->movement = false;
    this->it = keyboard.begin();
    this->end = keyboard.end();

    this->model_.update(gameClock);

    model_.set_default_model_color(gdl::Color(255,0,255));
    model_.cut_animation(this->model_, "Take 001", 40, 60, "Run");
    model_.cut_animation(this->model_, "Take 001", 0, 0, "Stop");

    while (it != end)
      {
	if (input.isKeyDown((*it).first) == true)
	  {
	    this->movement = true;
	    (this->*(*it).second)();
	  }
	++it;
      }

    if (movement == false)
      this->model_.play("Stop");
  }

  void		Bomberman::draw_player1(void)
  {
    //player1
    glPushMatrix();

    //glTranslatef(-((this->map_.x * 150.0f)), 0.0f, ((this->map_.y * 150.0f)));
    glTranslatef(this->move_x, 0.0f, this->move_y);
    glRotatef(this->rot_x, 0, 1, 0);

    this->model_.draw();

    glPopMatrix();
  }

  void		Bomberman::position_x_y(float x, float y)
  {
    sx = x;
    sy = y;

    x = x * 2;
    y = y * 2;

    x = (this->map_.x + (-x));
    y = (this->map_.y + (-y));

    this->move_x = -((x * 150.0f) - 150);
    this->move_y =  ((y * 150.0f) - 150);
  }
}
