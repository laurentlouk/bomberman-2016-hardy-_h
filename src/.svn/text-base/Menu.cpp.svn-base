//
// MyGame2.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/src
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Wed May 22 16:53:01 2013 laurent loukopoulos
// Last update Sat Jun  8 05:32:32 2013 laurent loukopoulos
//

#include	"../include/Menu.hh"

Menu::Menu(void)
{
  std::cout << " ---- Menu started ----" << std::endl;
}

Menu::~Menu(void)
{

}

void	Menu::initialize(void)
{
  if(!music_.OpenFromFile("sound/Menu.wav"))
    std::cout << "music failled to open" << std::endl;
  else
    {
      music_.Play();
      music_.SetLoop(true);
    }

  window_.setTitle("Crazy Bomberman");
  window_.setWidth(1200);
  window_.setHeight(900);

  //window_.setFullscreen(true);

  window_.create();

  camera_.initialize();

  objects_.push_back(new Primitive::BGMenu());
  //objects_.push_back(new Primitive::Rectangle());
  //objects_.push_back(new Model::Bomberman());
  //objects_.push_back(new Object::Cube());

  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void	Menu::update(void)
{
  std::list<AObject*>::iterator itb = this->objects_.begin();

  if (input_.isKeyDown(gdl::Keys::Return) == true)
    unload();
  else if (input_.isKeyDown(gdl::Keys::Escape) == true)
    {
      music_.Stop();
      glFlush();
      exit(0);
    }


  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);

  camera_.update(gameClock_, input_, window_.getWidth(), window_.getHeight());
}

void	Menu::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* bckgrnd black */
  glClearDepth(1.0f);

  std::list<AObject*>::iterator itb = this->objects_.begin();

  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();

  this->window_.display();
}

void	Menu::unload(void)
{
  music_.Stop();
  glFlush();
  std::cout << " ---- Menu ended ----" << std::endl;
  window_.close();
}
