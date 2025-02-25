/** file: test-ball.cpp
 ** brief: Tests the bouncing ball simulation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"
#include <iostream>


void run(Simulation& s, double dt) {
   for (int i = 0; i < 100; ++i) { 
       s.step(dt); 
       s.display(); 
   }
}


 // expect the ball to bounce around the box! 
 // linearly varying x values between +/-1 which increase, then decrease, then increase, etc.
 // y values will follow a concavic parabolic path wrt the x values
int main(int argc, char** argv)
{
	Ball ball;
	double dt = 0.01;
	run(ball, dt);


    return 0;
}

// Output looks reasonable
// To save to text file, run the following command:  x64/Debug/B16_lab.exe > src/ball.txt

// It is useful to separate data representation from low-level logic. It allows us to view the data in 
// a variety of formats without having to alter the code dictating the physical behaviour of the system
