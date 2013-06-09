//
// Ressource.hh for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Mon May 27 15:21:51 2013 laurent loukopoulos
// Last update Sat Jun  8 21:04:04 2013 laurent loukopoulos
//

#ifndef		__MAP_HPP__
#define		__MAP_HPP__

#include	<iostream>
#include	<sstream>
#include	<string>
#include	<fstream>
#include	<map>
#include	<GL/gl.h>
#include	<GL/glu.h>

#include	"AObject.hh"
#include	"Camera.hh"

#include	"Image.hpp"
#include	"Input.hpp"
#include	"Game.hpp"
#include	"GameClock.hpp"
#include	"Model.hpp"
#include	"Vector3f.hpp"

class		Map
{
public:
  Map();
  ~Map();

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
  void		draw(void);

  void		size(void);
  void		getInitMap(void);
  int		getTab(void);
  std::string	getModeMenu(void);
  void		changeMode(void);

  void		map1(void);
  void		map2(void);
  void		map3(void);

  int		**tab;
  int		x;
  int		y;

  std::string	nb_players;

private:
  char		*file;
  std::stringstream str;
  std::string	name_map;

  std::map<std::string, void (Map::*)()> map_conf;
  std::map<std::string, void (Map::*)()>::const_iterator it;
  std::map<std::string, void (Map::*)()>::const_iterator end;
};

#endif
