/** file: simulation.h
 ** brief: Simulation class (an interface)
 ** author: Andrea Vedaldi
 **/

#ifndef __simulation__
#define __simulation__

class Simulation
{
public:
    // these virtual functions will be implemented in the derived ball class
    // they have to be virtual, or the compiler will look for an implementation 
	// in the base class, which doesn't exist
	virtual void step(double dt) = 0;  
    virtual void display() = 0 ;
} ;


#endif /* defined(__simulation__) */
