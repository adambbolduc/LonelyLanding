/*
 * MouseManager.h
 *
 *  Created on: 2014-05-20
 *      Author: Adam
 */

#ifndef MOUSEMANAGER_H_
#define MOUSEMANAGER_H_

#include <set>

class MouseManager {
	friend class InputManager;

private:
	MouseManager();
	void buttonClicked(int button);
	void buttonReleased(int button);
	MouseManager& operator=(const MouseManager &mm2);
	void printButtonActivated() const;


	std::set<int> m_buttonActivated;

};

#endif /* MOUSEMANAGER_H_ */
