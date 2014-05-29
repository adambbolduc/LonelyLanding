/*
 * EventManager.h
 *
 *  Created on: 2014-05-17
 *      Author: Adam
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "InputEvent.h"
#include "KeyManager.h"
#include "MouseManager.h"
#include <queue>

class InputManager {

public:
	static bool init();


	static void keyPressed(int key);
	static void keyReleased(int key);
	static void printKeyActivated();

	static void buttonClicked(int button);
	static void buttonReleased(int button);
	static void printButtonActivated();

	static void pollEvents();
	static InputEvent* getNextEvent();
	static bool noEvent();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
private:
	static KeyManager keyManager;
	static MouseManager mouseManager;
	static std::queue<InputEvent*> inputEventQueue;

};

#endif /* INPUTMANAGER_H_ */
