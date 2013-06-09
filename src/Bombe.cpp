//
// Bombe.cpp for bomber in /home/hardy-_h//Epitech /tek2_2013/C++/bomberman/bomber
// 
// Made by hugo hardy-dessources
// Login   <hardy-_h@epitech.net>
// 
// Started on  Wed May 22 18:38:25 2013 hugo hardy-dessources
// Last update Fri Jun  7 19:16:20 2013 hugo hardy-dessources
//

#include "../include/Bomberman.hpp"

namespace       Model
{

  void	Bombe::init(float coord_x_, float coord_y_)
  {
    this->model_ = gdl::Model::load("assets/bomb.fbx");
    //    this->exploded = false;
    this->drop = false;
    this->coord_x = coord_x_;
    this->coord_y = coord_y_;
    this->coord_expl_x = 100000.0f;
    this->coord_expl_y = 100000.0f;
  }
  
  Bombe::~Bombe()
  {
  }
  
  void          Bombe::update(gdl::GameClock const & gameClock)
  {
    if(this->is_drop())
      {
	this->clock_.update();
	if(this->clock_.getTotalElapsedTime() > Bombe::lifetime && !this->exploded)
	  this->explode(gameClock);
      }
  }

  void          Bombe::draw_bombe(void)
  {
    glPushMatrix();
    glTranslatef(this->coord_y, 100.0f, this->coord_x);
    gdl::Model::Begin();
    this->model_.draw();
    gdl::Model::End();
    glPopMatrix();
  }

  bool		Bombe::is_drop() const
  {
    return(this->drop);
  }

  void		Bombe::explode(gdl::GameClock const &gameClock)
  {
    if(!this->exploded)
      {
	this->exploded = true;
	//	this->coord_expl_x = this->coord_x;
	//	this->coord_expl_y = this->coord_y;
	this->coord_x = 100000.0f;
	this->coord_y = 100000.0f;
	this->model_.update(gameClock);
	//	this->drop = false;
	this->clock_.pause();
	this->clock_.reset();
      }
  }
}
