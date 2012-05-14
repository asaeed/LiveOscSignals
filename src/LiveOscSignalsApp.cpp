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
#include "LiveOsc.h"
#include "boost/bind.hpp"

class LiveOscSignalsApp : public ci::app::AppBasic {
public:
	void setup();
	void prepareSettings( ci::app::AppBasic::Settings *settings );
	void mouseDown( ci::app::MouseEvent event );
	void update();
	void draw();
	void shutdown();

	void onBeatEvent( ci::osc::Message* message );

	LiveOsc liveOsc;
	ci::gl::Texture texture;
};

void LiveOscSignalsApp::prepareSettings( ci::app::AppBasic::Settings *settings ) {
	settings->setWindowSize( 800, 600 );
}

void LiveOscSignalsApp::setup() {
	std::cout << "Setting application path: " << getAppPath() << std::endl;
	chdir( getAppPath().c_str( ) );

	liveOsc.setup();

	// Use boost::bind, to bind our class's function, to our (this) specific instnace
	// _1 is a typedef for boost::arg - So we're creating a spot for the first argument in the function
	// note: adding "using namespace std" makes this not work because _1 becomes an ambiguous ref
	liveOsc.getBeatSignal()->connect(boost::bind(&LiveOscSignalsApp::onBeatEvent, this, _1));

	// Test loading a texture
	texture = ci::gl::Texture( ci::loadImage( ci::app::App::get()->loadResource( RES_WHEEL ) ) );
}

void LiveOscSignalsApp::mouseDown( ci::app::MouseEvent event ) {
}

void LiveOscSignalsApp::update() {
	liveOsc.update();
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

	//printOSC();


}

void LiveOscSignalsApp::onBeatEvent(ci::osc::Message* message){
	liveOsc.printOSCMessage(*message);
}


void LiveOscSignalsApp::shutdown() {
	std::cout << "Shutdown..." << std::endl;
	AppBasic::shutdown();
}
CINDER_APP_BASIC( LiveOscSignalsApp, ci::app::RendererGl )
