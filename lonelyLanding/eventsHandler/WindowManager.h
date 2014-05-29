/*
 * WindowManager.h
 *
 *  Created on: 2014-05-27
 *      Author: Adam
 */

#ifndef WINDOWMANAGER_H_
#define WINDOWMANAGER_H_

#include <GLFW/glfw3.h>


class WindowManager {

public:
	static bool createWindow(int width, int height);
	static void destroyWindow();
	static void setKeyCallback(void(* GLFWkeyfun)(GLFWwindow *, int, int, int, int));
	static void setMouseButtonCallback(void(* GLFWmousebuttonfun)(GLFWwindow *, int, int, int));
	static bool windowShouldClose();
	static void swapBuffer();
private:
	static GLFWwindow* window;
};

#endif /* WINDOWMANAGER_H_ */
