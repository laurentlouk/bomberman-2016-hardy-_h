//
// Bomberman.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Sat Jun  8 02:38:04 2013 laurent loukopoulos
// Last update Sat Jun  8 21:39:23 2013 laurent loukopoulos
//

#include	"../include/Bomberman.hpp"
#include	<iostream>

namespace	Model
{
  void		Bomberman::initialize(void)
  {
    this->game = 0;
    this->cam_.initialize();
    music_.OpenFromFile("sound/explo3.wav");
    this->bonus_.initialize();

    this->map_.initialize();
    this->trunks_.initialize();
    this->fire_P1.init(1, 1, 0);
    create_player1();
    this->bombe_P1.init(100000.0f, 100000.0f);
    if (this->map_.nb_players == "2")
      {
	create_player2();
	this->bombe_P2.init(100000.0f, 100000.0f);
      }
    this->text.setPosition(0,0);
    this->text_clock.setPosition(660,0);
    this->clock3_.reset();
    this->clock3_.play();
    this->power = 1;
    this->power2 = 1;
    this->speed = 20;
    this->speed2 = 20;
  }

  Bomberman::~Bomberman(void)
  {
    //delete this->model_;
  }

  void		Bomberman::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    std::stringstream ss;
    int		x1;
    int		y1;
    std::string	clock_str;
    int		x2;
    int		y2;
    int		c;

    c = this->clock3_.getTotalElapsedTime();
    ss << c;
    ss >> clock_str;
    this->clock3_.update();

    this->cam_.update(gameClock, input, 0, 0);
    std::string str = getBonus();
    this->text.setText(str);
    this->text_clock.setText(clock_str);

    game_player1(gameClock, input);
    this->bombe_P1.model_.update(gameClock);
    if (this->bombe_P1.is_drop() && this->bombe_P1.exploded)
      {
	this->clock1_.reset();
	this->clock1_.play();
	erase_map_trunk(this->bombe_P1.coord_expl_x, this->bombe_P1.coord_expl_y, this->power);
	this->fire_P1.init(this->bombe_P1.coord_expl_x, this->bombe_P1.coord_expl_y, this->power);
	this->fly_fire1 = false;
	this->bombe_P1.drop = false;
	music_.Play();
      }
    update_clock1(this->bombe_P1.coord_expl_x, this->bombe_P1.coord_expl_y);
    if (input.isKeyDown(gdl::Keys::N) == true && !this->bombe_P1.is_drop())
      {
	this->bombe_P1.exploded = false;
	this->bombe_P1.drop = true;
	this->bombe_P1.clock_.play();
	x1 =  -((((-this->move_x) / 150 ) - this->map_.x) / 2);
	y1 = ((((-this->move_y) / 150 ) + this->map_.y) / 2);
	this->bombe_P1.coord_expl_x = x1;
	this->bombe_P1.coord_expl_y = y1;
	bposition1_x_y(x1, y1);
	this->map_.tab[x1][y1] = 8;
      }
    this->bombe_P1.update(gameClock);
    
    if (this->map_.nb_players == "2")
      {
	game_player2(gameClock, input);
	this->bombe_P2.model_.update(gameClock);
	if (this->bombe_P2.is_drop() && this->bombe_P2.exploded)
	  {
	    this->clock2_.reset();
	    this->clock2_.play();
	    erase_map_trunk(this->bombe_P2.coord_expl_x, this->bombe_P2.coord_expl_y, this->power2);
	    this->fire_P2.init(this->bombe_P2.coord_expl_x, this->bombe_P2.coord_expl_y, this->power2);
	    this->fly_fire2 = false;
	    this->bombe_P2.drop = false;
	    music_.Play();
	  }
	update_clock2(this->bombe_P2.coord_expl_x, this->bombe_P2.coord_expl_y);
	if (input.isKeyDown(gdl::Keys::LShift) == true
	    && !this->bombe_P2.is_drop())
	  {
	    this->bombe_P2.exploded = false;
	    this->bombe_P2.drop = true;
	    this->bombe_P2.clock_.play();
	    x2 =  -((((-this->move2_x) / 150 ) - this->map_.x) / 2);
	    y2 = ((((-this->move2_y) / 150 ) + this->map_.y) / 2);
	    this->bombe_P2.coord_expl_x = x2;
	    this->bombe_P2.coord_expl_y = y2;
	    bposition2_x_y(x2, y2);
	    this->map_.tab[x2][y2] = 9;
	  }
	this->bombe_P2.update(gameClock);
      }
    float      	px1 = -((((-this->move_x) / 150 ) - this->map_.x) / 2);
    float      	py1 = ((((-this->move_y) / 150 ) + this->map_.y) / 2);
    if (this->bonus_.remove(px1, py1) == true)
      {
	int	rd = rand() % 3 + 1;
	if (rd == 2)
	  this->life1 += 1;
	else if (rd == 1)
	  this->speed += 10;
	else
	  this->power = 2;
      }
    float      	px2 = -((((-this->move2_x) / 150 ) - this->map_.x) / 2);
    float      	py2 = ((((-this->move2_y) / 150 ) + this->map_.y) / 2);
    if (this->bonus_.remove(px2, py2) == true)
      {
	int	rd2 = rand() % 3 + 1;
	if (rd2 == 2)
	  this->life2 += 1;
	else if (rd2 == 1)
	  this->speed2 += 10;
	else
	  this->power2 = 2;
      }
  }

  void		Bomberman::draw(void)
  {
    this->text.draw();
    this->text_clock.draw();
    this->cam_.initialize();

    this->bonus_.draw();
    draw_player1();
    this->bombe_P1.draw_bombe();
    this->fire_P1.draw();
    this->trunks_.draw();

    if (this->map_.nb_players == "2")
      {
	draw_player2();
	this->bombe_P2.draw_bombe();
	this->fire_P2.draw();
      }
  }

  void		Bomberman::bposition1_x_y(float x, float y)
  {
    b1x = x;
    b1y = y;

    x = x * 2;
    y = y * 2;

    x = (this->map_.x + (-x));
    y = (this->map_.y + (-y));

    this->bombe_P1.coord_x = ((y * 150.0f) - 150);
    this->bombe_P1.coord_y = -((x * 150.0f) - 150);
  }

  void		Bomberman::bposition2_x_y(float x, float y)
  {
    b2x = x;
    b2y = y;

    x = x * 2;
    y = y * 2;

    x = (this->map_.x + (-x));
    y = (this->map_.y + (-y));

    this->bombe_P2.coord_x = ((y * 150.0f) - 150);
    this->bombe_P2.coord_y = -((x * 150.0f) - 150);
  }

  void		Bomberman::update_clock1(int x1, int y1)
  {
    int	i = this->clock1_.getTotalElapsedTime();

    this->clock1_.update();
    if(i == 1 && this->fly_fire1 == false)
      {
	this->fire_P1.init(x1, y1, 0);
	this->fly_fire1 = true;
      }
    
  }

  void		Bomberman::update_clock2(int x1, int y1)
  {
    int	i = this->clock2_.getTotalElapsedTime();

    this->clock2_.update();
    if(i == 1 && this->fly_fire2 == false)
      {
	this->fire_P2.init(x1, y1, 0);
	this->fly_fire2 = true;
      }
    
  }

  void		Bomberman::life_check1()
  {
    this->life1 = this->life1 - 1;
    if (this->life1 == 0)
      {
	this->game = 2;
	std::cout<<"perso1 dead"<<std::endl;
	music_.Stop();
      }
  }

  void		Bomberman::life_check2()
  {
    this->life2 = this->life2 - 1;
    if (this->life2 == 0)
      {
	this->game = 1;
	std::cout<<"perso2 dead"<<std::endl;
	music_.Stop();
      }
  }

  void		Bomberman::erase_map_trunk(int x1, int y1, int power)
  {
    int		i = 1, y , x, y2, x2;

    while(power + 1 != i)
      {
	x = -((((-this->move_x) / 150 ) - this->map_.x) / 2);
	y = ((((-this->move_y) / 150 ) + this->map_.y) / 2);
	x2 = -((((-this->move2_x) / 150 ) - this->map_.x) / 2);
	y2 = ((((-this->move2_y) / 150 ) + this->map_.y) / 2);
	music_.Stop();

	if(x == (x1) && y == y1)
	  this->life_check1();
	if((x == (x1 + i) && y == y1) || (x == (x1 - i) && y == y1))
	  this->life_check1();
	if((x == (x1) && y == y1 + i) || (x == (x1) && y == y1 - i))
	  this->life_check1();

	if(x2 == (x1) && y2 == y1)
	  this->life_check2();
	if((x2 == (x1 + i) && y2 == y1) || (x2 == (x1 - i) && y2 == y1))
	  this->life_check2();
	if((x2 == (x1) && y2 == y1 + i) || (x2 == (x1) && y2 == y1 - i))
	  this->life_check2();

	this->map_.tab[x1][y1] = 0;

	if (this->map_.tab[x1 - 1][y1] != 1)
	  if (this->map_.tab[x1 - i][y1] == 2)
	    {
	      this->map_.tab[x1 - i][y1] = 0;
	      this->trunks_.remove(x1 - i, y1);
	    }
	if (this->map_.tab[x1 + 1][y1] != 1)
	  if (this->map_.tab[x1 + i][y1] == 2)
	    {
	      this->map_.tab[x1 + i][y1] = 0;
	      this->trunks_.remove(x1 + i, y1);
	    }
	if (this->map_.tab[x1][y1 - 1] != 1)
	  if (this->map_.tab[x1][y1 - i] == 2)
	    {
	      this->map_.tab[x1][y1 - i] = 0;
	      this->trunks_.remove(x1, y1 - i);
	    }
	if (this->map_.tab[x1][y1 + 1] != 1)
	  if (this->map_.tab[x1][y1 + i] == 2)
	    {
	      this->map_.tab[x1][y1 + i] = 0;
	      this->trunks_.remove(x1, y1 + i);
	    }
	i++;
      }
  }

  std::string		Bomberman::getBonus(void)
  {
    std::stringstream ss;
    std::string	      str1;
    std::string	      str2;
    std::string	      str3;

    ss.clear();
    str1 = "player 1 life : ";
    ss << this->life1;
    ss >> str2;
    str1 += str2;

    ss.clear();
    str1 += "\nplayer 1 speed : ";
    ss << this->speed;
    ss >> str2;
    str1 += str2;


    if (this->power == 2)
      str1 += "\nPLayer 1 : Bonus Boom !!!";

    ss.clear();
    str1 += "\n\nplayer 2 life : ";
    ss << this->life2;
    ss >> str3;
    str1 += str3;

    ss.clear();
    str1 += "\nplayer 2 speed : ";
    ss << this->speed2;
    ss >> str3;
    str1 += str3;

    if (this->power2 == 2)
      str1 += "\nPlayer 2 : Bonus Boom !!!";

    if (this->game == 0)
      return (str1);
    else if (this->game == 1)
      return ("player 1 has win !!!!");
    else if (this->game == 2)
      return ("player 2 has win !!!!");
  }
}
