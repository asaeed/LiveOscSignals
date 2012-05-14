/*
 * LiveOsc.h
 *
 *  Created on: May 13, 2012
 *      Author: asaeed
 */

#ifndef LIVEOSC_H_
#define LIVEOSC_H_

#include "OscListener.h"
#include <boost/signals2.hpp>
#include <iostream>

class LiveOsc {
public:
	// this typedef creates a simple shorthand, so that ButtonSignal refers to boost::signals2::signal<void( Button* )>
	// If you wanted you could use the long name instead, but its easier to typo
	typedef boost::signals2::signal<void( ci::osc::Message* )> OscSignal;

	LiveOsc();
	virtual ~LiveOsc();
	void setup();
	void update();

	void beatEvent(ci::osc::Message* m);

	void printOSCMessage( ci::osc::Message message );

	OscSignal* getBeatSignal() { return &_beatSignal; }; // Notice we return a pointer to the signal

private:
	ci::osc::Listener _listener;
	OscSignal    _beatSignal;
};


#endif /* LIVEOSC_H_ */
