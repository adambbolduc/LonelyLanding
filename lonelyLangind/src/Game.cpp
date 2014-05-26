/*
 * Game.cpp
 *
 *  Created on: 2014-05-14
 *      Author: Adam
 */

#include "Game.h"
#include "GameStateManager.h"
#include <GLFW/glfw3.h>


Game::Game() {
	m_gsm = new GameStateManager();
}

Game::~Game() {
	delete m_gsm;
}

void Game::update(){}
void Game::render(){}
void Game::keyPressed(int key){}
void Game::keyReleased(int key){}


