  #include	"../include/Primitive.hpp"
  #include	<iostream>
  #include <cstdlib>

namespace	Primitive
{

  void	BGMenu::initialize(void)
  {
    this->nbrMenu = 1;
    nbrNameMenu[11] = gdl::Image::load("photo/menu/menu11.png");
    nbrNameMenu[12] = gdl::Image::load("photo/menu/menu12.png");
    nbrNameMenu[21] = gdl::Image::load("photo/menu/menu21.png");
    nbrNameMenu[22] = gdl::Image::load("photo/menu/menu22.png");
    nbrNameMenu[31] = gdl::Image::load("photo/menu/menu31.png");
    nbrNameMenu[32] = gdl::Image::load("photo/menu/menu32.png");
    nbrNameMenu[41] = gdl::Image::load("photo/menu/menu41.png");
    nbrNameMenu[42] = gdl::Image::load("photo/menu/menu42.png");
    nbrNameMenu[51] = gdl::Image::load("photo/menu/menu51.png");
    nbrNameMenu[52] = gdl::Image::load("photo/menu/menu52.png");
    this->check = 1;
    this->nbrMenuPlayer = 1;
    this->nbrMenu = 10;

    this->keyMenu[gdl::Keys::Up] = &BGMenu::Up;
    this->keyMenu[gdl::Keys::Down] = &BGMenu::Down;
    this->keyMenu[gdl::Keys::Left] = &BGMenu::Left;
    this->keyMenu[gdl::Keys::Right] = &BGMenu::Right;
  }

  bool BGMenu::is_readable(const std::string & file) 
{ 
    std::ifstream fichier(file.c_str()); 
    return !fichier.fail(); 
} 

  void BGMenu::sendParam()
  {
    std::stringstream	ss;
    std::ofstream myfile;
    std::string	str;
    std::string str2;
    int nbr = this->nbrMenu / 10;

    if (nbr == 4)
      nbr = rand() % 3 + 1;

    if (nbr == 5)
    {
      if (!is_readable(".sauv"))
        nbr = rand() % 3 + 1; 
    }

    ss.clear();
    ss << nbr;
    ss >> str;

    str += "\n";

    ss.clear();
    ss << this->nbrMenuPlayer;
    ss >> str2;

    myfile.open (".config");

    str += str2 + '\n';
    myfile << str;

    myfile.close();
  }

  void BGMenu::setNbrMenu(int nb)
  {
    this->nbrMenu = this->nbrMenu + nb;
    if (this->nbrMenu >= 60)
      this->nbrMenu = 10;
    else if (this->nbrMenu <= 0)
      this->nbrMenu = 50;
  }

  void   BGMenu::Right(gdl::GameClock const & gameClock)
  {

    this->pause_.pause(gameClock, 0.30f);
    this->nbrMenuPlayer = 2;
  }

  void   BGMenu::Left(gdl::GameClock const & gameClock)
  {

    this->pause_.pause(gameClock, 0.30f);
    this->nbrMenuPlayer = 1;
  }

  void   BGMenu::Up(gdl::GameClock const & gameClock)
  {

    this->pause_.pause(gameClock, 0.30f);
    setNbrMenu(-10);
  }

  void    BGMenu::Down(gdl::GameClock const & gameClock)
  {
    this->pause_.pause(gameClock, 0.30f);
    setNbrMenu(10);
  }

  void  BGMenu::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->it = nbrNameMenu.begin();
    this->end = nbrNameMenu.end();

    this->itMenu = keyMenu.begin();
    this->endMenu = keyMenu.end();

    if (this->check == 1)
    {


	//        this->pause_.pause(gameClock, 7.0f);
     if (input.isKeyDown(gdl::Keys::B) == true)
     {
       this->Menu_ = gdl::Image::load("photo/menu/splaschscreenok.png");
       this->Menu_.bind();
     }
     else
     {
       this->Menu_ = gdl::Image::load("photo/menu/splaschscreen.png");
       this->Menu_.bind();
     }
     this->check = 2;
   }

   if (this->check == 2)
   {
     while (itMenu != endMenu)
     {
       if (input.isKeyDown((*itMenu).first) == true)
         (this->*(*itMenu).second)(gameClock);
       ++itMenu;
     }

     this->nbrMenuTotal = this->nbrMenu + this->nbrMenuPlayer;
     while(it != end)
     {
       if (this->nbrMenuTotal == (*it).first)
         this->Menu_ = (*it).second;
       ++it;
     }
     this->Menu_.bind();
     sendParam();
   }
 } 

 void	BGMenu::draw(void)
 {
  glBegin(GL_QUADS);

  glPushMatrix();

    /// Vertex superieur gauche
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-900.0f, 650.0f, 0.0f);
    /// Vertex inferieur gauche
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-900.0f, -650.0f, 0.0f);
    /// Vertex inferieur droit
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(900.0f, -650.0f, 0.0f);
    /// Vertex superieur droit
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(900.0f, 650.0f, 0.0f);

  glPopMatrix();

  glEnd();
}
}
