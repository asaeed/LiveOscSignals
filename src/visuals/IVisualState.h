/*
 * IVisualState.h
 *
 *  Created on: May 21, 2012
 *      Author: asaeed
 */

#ifndef IVISUALSTATE_H_
#define IVISUALSTATE_H_

namespace visuals {
	class IVisualState {
		public:
			virtual ~IVisualState(){};

			virtual void enter( double aCurrentTime ) {
				std::cout << "Entering IVisualState" << std::endl;
				timeDelta = 0;
				currentTime = aCurrentTime;
			};

			virtual void update( double newCurrentTime ) {
				double dt = newCurrentTime - currentTime;
				timeDelta += dt;
				currentTime = newCurrentTime;
			};
			virtual void draw() = 0;
			virtual void exit() { std::cout << "Exiting IVisualState" << std::endl; };

		protected:
			double currentTime;			// Bookkeeping variable for time
			double timeDelta;			// Every tick this is incremented - it represents how long the state has been 'active'. Reset on exit

	};
}


#endif /* IVISUALSTATE_H_ */
