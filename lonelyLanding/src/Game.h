/*
 * Game.h
 *
 *  Created on: 2014-05-14
 *      Author: Adam
 */

#ifndef GAME_H_
#define GAME_H_

#include "GameStateManager.h"
#include <GLFW/glfw3.h>

class Game {
public:
	Game();
	virtual ~Game();
	void update();
	void render();
	void keyPressed(int key);
	void keyReleased(int key);


private:
	GameStateManager* m_gsm;

};

#endif /* GAME_H_ */
