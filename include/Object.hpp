//
// Object.hh for bbman in /home/loukop_l//bomberman/bb/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Mon May 20 00:28:53 2013 laurent loukopoulos
// Last update Sat Jun  8 05:49:23 2013 laurent loukopoulos
//

#ifndef		__OBJECT_HPP__
#define		__OBJECT_HPP__

#include        <GL/gl.h>
#include        <GL/glu.h>

#include        "Image.hpp"
#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"AObject.hh"
#include	"Vector3f.hpp"
#include	"Map.hpp"

namespace	Object
{
  class		Cube : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
    void	create(float, float);
    void	position_x_y(float, float);

  private:
    gdl::Image	texture_;
    Vector3f	rotation_;
    float	slide;
    Map		map_;
  };

  class		Pyramide : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
  private:
    gdl::Image	texture_;
    Vector3f	rotation_;
  };
}

#endif
