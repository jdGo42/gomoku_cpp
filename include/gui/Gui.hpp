#ifndef GUI_HPP
#define GUI_HPP

#include "Define.hpp"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define GUI_RATE 10
#define GUI_TIME_LOOP 1000 / GUI_RATE

#ifndef GUI_WIN_W  // defined in compiler -DGUI_WIN_W=xxx
	#define GUI_WIN_W 800
#endif
#define GUI_WIN_H (GUI_WIN_W * 0.7)
#define GUI_BOARD_SZ GUI_WIN_H
#define GUI_BOARD_START_X static_cast<int>(GUI_WIN_W - GUI_BOARD_SZ)

#define GUI_DEFAULT_FONT "font/Roboto/Roboto-Regular.ttf"
#define GUI_TEXT_SIZE (GUI_WIN_H*0.04)
#define GUI_TEXT_SIZE_NUMBER (GUI_WIN_H*0.02)
#define GUI_LINE_SPACE_MENU (GUI_TEXT_SIZE * 3)
#define GUI_LINE_SPACE_GAME (GUI_TEXT_SIZE * 1.5)

// all colors are in format RGBA
#define GUI_COLOR_BG 0x252525FF
#define GUI_COLOR_BOARD_BG 0xFFBB64FF
#define GUI_COLOR_1 0x000000FF
#define GUI_COLOR_2 0xFFFFFFFF
#define GUI_COLOR_MARKER_HELP 0x00FF00FF
#define GUI_COLOR_DESTROYED 0xFF0000FF
#define GUI_COLOR_WIN 0x00FF00FF
#define GUI_COLOR_LOOSE 0xFF0000FF
#define GUI_COLOR_LAST_STONE 0x3EBDFFFF
#define GUI_COLOR_VULNERABILITY 0xFF0000FF
#define GUI_COLOR_PLAYER_ACT 0x3EBDFFFF
#define GUI_COLOR_TEXT_MENU 0xFFFFFFFF

class Game;

enum typeGui {
	GUI_TYPE_MENU, GUI_TYPE_GAME, GUI_TYPE_LOADING
};

class Gui {
	public:
		Gui(Game &game);
		void init();  // init the gui -> called by Gui
		void run();  // run the Gui: handle events, draw, ...
		virtual ~Gui();
		void quit();
		sf::Color getColor(int stone) const;  // get color corresponding to the player
		sf::Color getRevColor(int stone) const;  // get the reverse color corresponding to the player
		int getComplementaryColor(int color) const;
		typeGui getGuiType() const;
		void setGuiType(typeGui newType);

		Game	&game;
	protected:
		void event();  // handle events -> called by run
		void eventMenu();  // handle event for the menu -> called by event
		void eventGame();  // handle event for the game -> called by event
		void draw();  // draw the menu or the game -> called by run
		void drawMenu();  // draw the menu -> called by draw
		void drawGame();  // draw the game -> called by draw

		sf::RenderWindow	*_win;
		sf::Font			_font;
		typeGui				_typeGui;
		bool				_clicked;
};

#endif