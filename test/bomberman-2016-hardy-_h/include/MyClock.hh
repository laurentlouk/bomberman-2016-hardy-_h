//
// MyClock.hh for bbman in /home/loukop_l//Dropbox/Bomberman/loukop_l/include
// 
// Made by laurent loukopoulos
// Login   <loukop_l@epitech.net>
// 
// Started on  Tue May 28 14:53:04 2013 laurent loukopoulos
// Last update Tue May 28 14:59:50 2013 laurent loukopoulos
//

#ifndef		__MYCLOCK_HH__
#define		__MYCLOCK_HH__

class		MyClock
{
public:
  MyClock();
  ~MyClock();
  void		get_pause(void);
  void		get_replay(void);

private:
  float		clock_;
}

#endif
