/*
 * LiveOsc.cpp
 *
 *  Created on: May 13, 2012
 *      Author: asaeed
 */

#include "LiveOsc.h"
#include "boost/bind.hpp"

LiveOsc::LiveOsc() {

}

LiveOsc::~LiveOsc() {
}

void LiveOsc::setup() {
	_listener.setup(9001);
}

void LiveOsc::update() {
	while (_listener.hasWaitingMessages()) {
		ci::osc::Message message;
		_listener.getNextMessage(&message);
		printOSCMessage(message);

		if (message.getAddress() == "/live/beat")
			beatEvent(&message);
	}
}

void LiveOsc::beatEvent(ci::osc::Message* m) {
	_beatSignal(m);
}

void LiveOsc::printOSCMessage( ci::osc::Message message ) {
	std::cout << "--> " << message.getAddress() << "  ";
	std::cout << "#args:" << message.getNumArgs() << "  ";
	for (int i = 0; i < message.getNumArgs(); i++) {
		std::cout << "[" << i << "]";
		std::cout << message.getArgTypeName(i);
		if (message.getArgType(i) == ci::osc::TYPE_INT32){
			try {
				std::cout << ": "<< message.getArgAsInt32(i);
			}
			catch (...) {
				std::cout << "Exception reading argument as int32" << std::endl;
			}

		}else if (message.getArgType(i) == ci::osc::TYPE_FLOAT){
			try {
				std::cout << ": " << message.getArgAsFloat(i);
			}
			catch (...) {
				std::cout << "Exception reading argument as float" << std::endl;
			}
		}else if (message.getArgType(i) == ci::osc::TYPE_STRING){
			try {
				std::cout << ": " << message.getArgAsString(i).c_str();
			}
			catch (...) {
				std::cout << "Exception reading argument as string" << std::endl;
			}
		}
		std::cout << "  ";
	}
	std::cout << std::endl;
}


