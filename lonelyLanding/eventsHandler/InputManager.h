/*
 * EventManager.h
 *
 *  Created on: 2014-05-17
 *      Author: Adam
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "KeyManager.h"
#include "MouseManager.h"

class InputManager {

public:
	static void keyPressed(int key);
	static void keyReleased(int key);
	static void printKeyActivated();

	static void buttonClicked(int button);
	static void buttonReleased(int button);
	static void printButtonActivated();
private:
	static KeyManager keyManager;
	static MouseManager mouseManager;
};

#endif /* INPUTMANAGER_H_ */
