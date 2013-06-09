//
// MyGame.cpp for bbman in /home/loukop_l//bomberman/bb
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Fri May 17 01:40:36 2013 laurent loukopoulos
// Last update Sat Jun  8 17:29:55 2013 laurent loukopoulos
//

#include	"../include/MyGame.hh"

MyGame::MyGame(void)
{
  std::cout << " ---- game started ----" << std::endl;
}

MyGame::~MyGame(void)
{

}

void	MyGame::initialize(void)
{
  if(!music_.OpenFromFile("sound/Menu"))
    std::cout << "music failled to open" << std::endl;
  else
    {
      music_.Play();
      music_.SetLoop(true);
    }

  window_.setTitle("Crazy Bomberman");
  window_.setWidth(1600);
  window_.setHeight(1000);

  window_.create();

  camera_.initialize();

  map_.initialize();

  std::cout << "this-> x : " << map_.x << std::endl;
  std::cout << "this-> y : " << map_.y << std::endl;

  objects_.push_back(new Primitive::Rectangle());
  objects_.push_back(new Model::Bomberman());
  objects_.push_back(new Object::Cube());

  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void	MyGame::update(void)
{
  std::list<AObject*>::iterator itb = this->objects_.begin();

  if (input_.isKeyDown(gdl::Keys::Escape) == true)
    unload();

  if (input_.isKeyDown(gdl::Keys::T) == true && this->pause_.pauseall == false)
    this->pause_.pauseall = true;
  else if (input_.isKeyDown(gdl::Keys::U) == true && this->pause_.pauseall == true)
    this->pause_.pauseall = false;


  if (this->pause_.pauseall == false)
    {
      for (; itb != this->objects_.end(); ++itb)
	(*itb)->update(gameClock_, input_);

      camera_.update(gameClock_, input_, window_.getWidth(), window_.getHeight());
    }
}

void	MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* bckgrnd black */
  glClearDepth(1.0f);

  std::list<AObject*>::iterator itb = this->objects_.begin();

  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();

  this->window_.display();
}

void	MyGame::unload(void)
{
  music_.Stop();
  glFlush();
  std::cout << " ---- game ended ----" << std::endl;
  exit(0);
}
