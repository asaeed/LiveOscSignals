/*
 * VisualStateMachine.h
 *
 *  Created on: May 21, 2012
 *      Author: asaeed
 */

#ifndef VISUALSTATEMACHINE_H_
#define VISUALSTATEMACHINE_H_

#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

#include <boost/function.hpp>

// FWD
namespace visuals { class IVisualState; };

namespace visuals {

	class VisualStateMachine {
		public:
			VisualStateMachine();
			~VisualStateMachine();

			void update();
			void draw();
			void setNextState( IVisualState* state ) { nextState = state; };

		private:
			void setInitialState( IVisualState* state );
			void changeState( IVisualState* state );
			void gotoPreviousState();
			void gotoNextState();

			IVisualState* currentState;
			IVisualState* previousState;
			IVisualState* nextState;

};

}


#endif /* VISUALSTATEMACHINE_H_ */
