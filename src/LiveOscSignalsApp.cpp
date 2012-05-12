/**
 * LiveOscSignalsApp
 * App contains a class LiveOscSignals that monitors LiveOSC and fires events in main app
 *
 * Ahmad Saeed
 * http://niltoid.com
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Vector.h"
#include "cinder/app/MouseEvent.h"
#include "cinder/Rand.h"
#include "Resources.h"
#include "gl.h"
#include "OscListener.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LiveOscSignalsApp : public ci::app::AppBasic {
public:
	void setup();
	void prepareSettings( ci::app::AppBasic::Settings *settings );
	void mouseDown( ci::app::MouseEvent event );
	void update();
	void draw();
	void shutdown();
	void printOSC();
	void printOSCMessage( ci::osc::Message message );

	ci::osc::Listener listener;
	ci::gl::Texture texture;
};

void LiveOscSignalsApp::prepareSettings( ci::app::AppBasic::Settings *settings ) {
	settings->setWindowSize( 800, 600 );
}

void LiveOscSignalsApp::setup() {
	std::cout << "Setting application path: " << getAppPath() << std::endl;
	chdir( getAppPath().c_str( ) );

	listener.setup(9001);

	// Test loading a texture
	texture = ci::gl::Texture( ci::loadImage( ci::app::App::get()->loadResource( RES_WHEEL ) ) );
}

void LiveOscSignalsApp::mouseDown( ci::app::MouseEvent event ) {
}

void LiveOscSignalsApp::update() {

}
void LiveOscSignalsApp::draw() {
	// clear out the window with black
	/*
	ci::Color aColor = ci::Color( 0, 0, 0 );
	aColor.r = fabs( cosf(getElapsedFrames() * 0.008) );
	aColor.g = fabs( sinf(getElapsedFrames() * 0.01) );
	aColor.b = (float) getMousePos().x / getWindowWidth();

	ci::gl::clear( ci::Color( 0, 0, 0 ) );

	ci::gl::color( ci::Color(aColor * 0.5) );
	ci::gl::drawLine( ci::Vec2f(getMousePos()), ci::Vec2f( getWindowCenter() ) );


	if ( texture ) {
		ci::gl::color( ci::ColorA(1.0f, 1.0f, 1.0f, 1.0f) );
		ci::gl::draw( texture, getWindowCenter() );
	}
	*/

	printOSC();

}

void LiveOscSignalsApp::printOSC() {
	while (listener.hasWaitingMessages()) {
			ci::osc::Message message;
			listener.getNextMessage(&message);
			printOSCMessage(message);
	}
}

void LiveOscSignalsApp::printOSCMessage( ci::osc::Message message ) {
	console() << "New message received" << std::endl;
	console() << "Address: " << message.getAddress() << std::endl;
	console() << "Num Arg: " << message.getNumArgs() << std::endl;
	for (int i = 0; i < message.getNumArgs(); i++) {
		console() << "-- Argument " << i << std::endl;
		console() << "---- type: " << message.getArgTypeName(i) << std::endl;
		if (message.getArgType(i) == ci::osc::TYPE_INT32){
			try {
				console() << "------ value: "<< message.getArgAsInt32(i) << std::endl;
			}
			catch (...) {
				console() << "Exception reading argument as int32" << std::endl;
			}

		}else if (message.getArgType(i) == ci::osc::TYPE_FLOAT){
			try {
				console() << "------ value: " << message.getArgAsFloat(i) << std::endl;
			}
			catch (...) {
				console() << "Exception reading argument as float" << std::endl;
			}
		}else if (message.getArgType(i) == ci::osc::TYPE_STRING){
			try {
				console() << "------ value: " << message.getArgAsString(i).c_str() << std::endl;
			}
			catch (...) {
				console() << "Exception reading argument as string" << std::endl;
			}

		}
	}
}

void LiveOscSignalsApp::shutdown() {
	std::cout << "Shutdown..." << std::endl;
	AppBasic::shutdown();
}
CINDER_APP_BASIC( LiveOscSignalsApp, ci::app::RendererGl )
