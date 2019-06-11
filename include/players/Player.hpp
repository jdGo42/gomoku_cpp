#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Game;

class Player {
	public:
		Player(Game &game, int _color);
		virtual ~Player();
		void	moving();  // call this function at the player turn
		void	click(int x, int y);
		int		getColor() const;
		void	incrNbDestroyedStones();
		int		getNbDestroyedStones() const;
		void	setWinAligned();
		double	getTimeLastMove() const;
		virtual std::string getType() const;
		void	incrNbStones();
		void	decrNbStones();
		int		getNbStones() const;
		bool	getWinAligned() const;

		Game	&game;
	protected:
		virtual void move();  // this function is called by moving (redefined in child)

		int		_color;
		int		_clickedPos[2];
		double	_timeLastMove;
	private:
		Player();
		int		_nbDestroyedStones;
		int		_nbStones;
		bool	_winAligned;
};

#endif