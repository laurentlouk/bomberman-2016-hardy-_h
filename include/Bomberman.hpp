//
// Bomberman.hh for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 21 09:25:34 2013 laurent loukopoulos
// Last update Sun Jun  9 21:37:49 2013 laurent loukopoulos
//

#ifndef		__BONBERMAN_HPP__
#define		__BONBERMAN_HPP__

#include	<iostream>
#include	<sstream>
#include	<map>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<SFML/Audio.hpp>

#include	"AObject.hh"
#include	"Object.hpp"
#include	"MyGame.hh"
#include	"Camera.hh"
#include	"Map.hpp"
#include	"Text.hpp"
#include	"MyPause.hh"
#include	"Camera.hh"
#include	"Window.hpp"

#include	"Image.hpp"
#include	"Input.hpp"
#include	"Game.hpp"
#include	"GameClock.hpp"
#include	"Model.hpp"
#include	"Vector3f.hpp"

namespace	Model
{
  class		Bonus
  {
  public:
    void	initialize(void);
    bool	remove(int,int);
    void	draw(void);
    void	create(float, float);
    void	position_x_y(float, float);

    float	x;
    float	y;

  private:
    Map		map_;
    gdl::Image	texture_;
    float	z;
  };

  class		Trunks
  {
  public:
    void	initialize(void);
    void	remove(int,int);
    void	draw(void);
    void	create(float, float);
    void	position_x_y(float, float);

    int		**tab;

    std::map<int,int> trunk_map;
    std::map<int,int>::const_iterator it;
    std::map<int,int>::const_iterator end;

  private:
    Map		map_;
    gdl::Image	texture_;
    float	z;
  };

  class         Bombe
  {
  public:
    static const float lifetime = 1.5f;
    
    gdl::Model  model_;
    gdl::Clock	clock_;
    bool	exploded;
    bool        drop;
    float       coord_x;
    float       coord_y;
    float	coord_expl_x;
    float	coord_expl_y;
    
    void    init(float coord_x, float coord_y);
    ~Bombe();
    void        update(gdl::GameClock const &);
    void        draw_bombe(void);
    bool	is_drop() const;
    void	explode(gdl::GameClock const &);
  };

  class		Fire
  {
  public:
    static const float lifetime_bomb = 1.0f;
    static const float lifetime = 5.0f;
    
    void        init(float, float, int);
    void        update();
    void        draw(void);
    void        create(float, float);
    void        position_x_y(float, float);

    gdl::Clock	clock_;
    bool	fire_on;
    bool	fire_off;
    
  private:
    gdl::Image  texture_;
    Vector3f    rotation_;
    float       slide;
    Map         map_;

    int		coord_bomb_x;
    int		coord_bomb_y;
    int		power_;
  };

  class		Bomberman : public AObject
  {
  public:
    ~Bomberman(void);
    
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
    void	erase_map_trunk(int, int, int);
    void	update_clock1(int, int);
    void	update_clock2(int, int);
    void	life_check1();
    void	life_check2();
    void	life_check3();
    std::string	getBonus(void);
    /* player 1 */

    void	create_player1(void);
    void	game_player1(gdl::GameClock const &, gdl::Input &);
    void	draw_player1(void);

    void	position_x_y(float, float);

    void	Up(void);
    void	Down(void);
    void	Left(void);
    void	Right(void);

    void	bposition1_x_y(float, float);
    /* player 1 */

    /* player 2 */

    void	create_player2(void);
    void	game_player2(gdl::GameClock const &, gdl::Input &);
    void	draw_player2(void);

    void	position2_x_y(float, float);

    void	Z(void);
    void	S(void);
    void	Q(void);
    void	D(void);

    void	bposition2_x_y(float, float);

    /* player 2 */

    /**** IA *****/

    void        init_Ia(void);
    void        updt_Ia(void);
    void        drw_Ia(void);
    float       up_Ia(void);
    float       down_Ia(void);
    float	left_Ia(void);
    float	right_Ia(void);

    void	positionia_x_y(float, float);

    /**** IA *****/

  private:

    /* player 1 */

    gdl::Model		model_; // j1
    Model::Bombe	bombe_P1; //j1
    Model::Fire		fire_P1; //j2

    std::map<gdl::Keys::Key, void (Bomberman::*)()> keyboard;
    std::map<gdl::Keys::Key, void (Bomberman::*)()>::const_iterator it;
    std::map<gdl::Keys::Key, void (Bomberman::*)()>::const_iterator end;

    bool	movement; // en mouvement ou pas j1

    gdl::Clock	clock;

    float	move_x;  // position du j1
    float	move_y;  // position du j1
    float	rot_x;	 // rotation du j1

    int		life1;

    float	moveb_x; // position bombe j1
    float	moveb_y; // position bombe j1

    float	sx;
    float	sy;

    float	b1x;
    float	b1y;

    int		power;
    float	speed;

    /* player 1 */

    /* player 2 */

    gdl::Model		model2_; // j2
    Model::Bombe	bombe_P2; //j2
    Model::Fire		fire_P2; //j2

    std::map<gdl::Keys::Key, void (Bomberman::*)()> keyboard2;
    std::map<gdl::Keys::Key, void (Bomberman::*)()>::const_iterator it2;
    std::map<gdl::Keys::Key, void (Bomberman::*)()>::const_iterator end2;

    bool	movement2; // en mouvement ou pas j2

    gdl::Clock	clock2;

    float	move2_x;  // position du j2
    float	move2_y;  // position du j2
    float	rot2_x;	 // rotation du j2

    int		life2;

    float	sx2;
    float	sy2;

    float	b2x;
    float	b2y;

    int		power2;
    float	speed2;

    /* player 2 */

    /**** IA ****/
    gdl::Model          i_a1;
    float               posIa_x;
    float               posIa_y;
    float               rotIa_x;
    float		check_pos_x;
    float		check_pos_y;
    bool		change;
    float		sx3;
    float		sy3;
    float		speed3;
    /**** IA ****/

    Map		map_;
    Trunks	trunks_;
    Bonus	bonus_;
    gdl::Text	text;
    gdl::Text	text_clock;
    MyPause	pause_;
    gdl::Clock	clock1_;
    bool	fly_fire1;
    gdl::Clock	clock2_;
    bool	fly_fire2;
    Camera	cam_;
    gdl::Clock	clock3_;
    gdl::Window	window_;
    int		game;
    sf::Music	music_;
    sf::Music	music2_;
  };
}

#endif
