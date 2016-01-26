/*
 * This class acts as Observer from Observer Design pattern.
 * Objects from this class get registered with subject. Subject call its update function
 * in case of any notification.
 */
#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
	Observer();
	virtual ~Observer();
	virtual void update() = 0;

};

#endif /* OBSERVER_H_ */
