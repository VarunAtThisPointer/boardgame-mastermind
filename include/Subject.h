/*
 * Subject class from Observer Design Pattern
 * It registered the list Of Observers with itself and updates them all
 * in acse of notification
 */
#ifndef SUBJECT_H_
#define SUBJECT_H_
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include "Observer.h"

 using namespace std::placeholders;

class Subject {
	 std::vector< std::shared_ptr<Observer> > m_ListOfObservers;
public:
	Subject(){}
	virtual ~Subject(){}
	void attach( std::shared_ptr<Observer>  observerPtr);
	void notifyAllObservers();
};

#endif /* SUBJECT_H_ */
