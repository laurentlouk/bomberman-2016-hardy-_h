//
// Map.cpp for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/src
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Mon May 27 15:49:46 2013 laurent loukopoulos
// Last update Tue Jun  4 20:26:00 2013 laurent loukopoulos
//

#include	"../include/Map.hpp"
#include	<iostream>

Map::Map()
{
  this->map_conf["1"] = &Map::map1;
  this->map_conf["2"] = &Map::map2;
  this->map_conf["3"] = &Map::map3;
}

Map::~Map()
{

}

void		Map::map1(void)
{
  this->name_map = ".map1";
}

void		Map::map2(void)
{
  this->name_map = ".map2";
}

void		Map::map3(void)
{
  this->name_map = ".map3";
}

void		Map::initialize()
{
  getInitMap();
}

void		Map::update(gdl::GameClock const &, gdl::Input &)
{

}

void		Map::getInitMap(void)
{
  std::string	map_s;
  std::stringstream ss;

  changeMode();

  size();

  this->tab = new int* [this->x];
  for (int i=0; i < this->x; i++)
    this->tab[i] = new int[this->y];

  for (int i=0; i < this->x; i++)
    for (int j=0; j < this->y; j++)
      {
	this->tab[i][j] = 0;
      }

  std::ifstream ifs (this->name_map.c_str());

  ifs.is_open();

  while (ifs.get() != '\n') {}

  char c = ifs.get();

  while (ifs.good())
    {
      if (c != '\n')
	map_s += c;
      c = ifs.get();
    }
  ifs.close();

  int	k = 0;
  for (int i=0; i < this->x; i++)
    for (int j=0; j < this->y; j++)
      {
	ss.clear();
	ss << map_s.at(k++);
	ss >> this->tab[i][j];
      }
}

void		Map::changeMode(void)
{
  std::string	mode = getModeMenu();
  std::string	mode1 = mode.substr(0,1);
  this->nb_players = mode.substr(2,1);

  this->it = this->map_conf.begin();
  this->end = this->map_conf.end();

  for (; this->it != this->end; ++it)
    {
      if (mode1.find((*it).first) != std::string::npos)
	(this->*(*it).second)();
    }
}

void		Map::size(void)
{
  std::ifstream ifs (this->name_map.c_str());
  std::string	num1;
  std::string	num2;
  std::stringstream ss;
  char		c;

  ifs.is_open();
  c = ifs.get();

  while (ifs.good() && (c != 'x')) 
    {
      num1 += c;
      c = ifs.get();
    }

  c = ifs.get();
  while (ifs.good() && (c != '\n')) 
    {
      num2 += c;
      c = ifs.get();
    }

  ss << num1 << ' ' << num2;
  ss >> this->x >> this->y;

  ifs.close();
}

std::string		Map::getModeMenu(void)
{
  std::ifstream	ifs;
  std::string	mode;
  char		c;

  ifs.open(".config");
  while (ifs.good())
    {
      c = ifs.get();
      mode += c;
    }
  ifs.close();

  return (mode);
}

void		Map::draw()
{

}
