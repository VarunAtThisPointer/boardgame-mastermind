#include "Subject.h"
/*
 * Attaches the Observer with the Subject i.e. add the Observer pointer in list
 */
void Subject::attach( std::shared_ptr<Observer>  observerPtr){
	m_ListOfObservers.push_back(observerPtr);
}

/*
 * Notifies all the registered Observers by calling its update function.
 */
void Subject::notifyAllObservers(){
   std::for_each(m_ListOfObservers.begin(), m_ListOfObservers.end(), std::bind(&Observer::update, _1));
}
