#include "EventDispatcher.h"

void EventDispatcher::addListener( Listener *l )
{
	mListeners.push_back(l);
}

void EventDispatcher::removeListener( Listener *l )
{
	mListeners.erase( std::remove( mListeners.begin(), mListeners.end(), l ), mListeners.end() );
	//having toruble with the rmove function...
}

void EventDispatcher::dispatchEvent()
{
	for( std::vector<Listener*>::iterator listener = mListeners.begin(); listener != mListeners.end(); ++listener  )
	{
		(*listener)->handleEvent();
	}
}