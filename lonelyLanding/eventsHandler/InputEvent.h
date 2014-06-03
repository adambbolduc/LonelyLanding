/*
 * InputEvent.h
 *
 *  Created on: 2014-05-21
 *      Author: Adam
 */

#ifndef INPUTEVENT_H_
#define INPUTEVENT_H_

#define GE_KEY_EVENT 1
#define GE_MOUSE_EVENT 2
#define GE_KEY_PRESS 3
#define GE_KEY_RELEASE 4
#define GE_MOUSE_PRESS 5
#define GE_MOUSE_RELEASE 6


class InputEvent {
public:
	InputEvent(int type);
	virtual void printEvent() =0;
	virtual ~InputEvent();
	unsigned int getType() const;
protected:
	unsigned int m_type;

};

class InputKeyEvent : public InputEvent {
public:
	InputKeyEvent(int key, int action);
	void printEvent();
	int getKey() const;
	int getAction() const;
private:
	int m_key;
	int m_action;
};

class InputMouseEvent : public InputEvent{
public:
	InputMouseEvent(int button, int action, double x, double y);
	void printEvent();

private:
	int m_button;
	int m_action;
	int m_x,m_y;
};



#endif /* INPUTEVENT_H_ */
