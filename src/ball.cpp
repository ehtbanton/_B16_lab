/** file: ball.cpp
 ** brief: Ball class - implementation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

#include <iostream>

Ball::Ball(): // this is the constructor, where the ball object is instantiated and initialized with the following values:
r(0.1),   // ball radius
x(0),     // x coordinate
y(0),     // y coordinate
vx(0.3),  // x velocity
vy(-0.1), // y velocity
g(9.8),   // gravity acceleration
m(1),     // ball mass
// and the geometry of the box containing the ball:
xmin(-1), xmax(1), ymin(-1), ymax(1)
{}

// Operator overloading for the Ball class...
Ball::Ball(double r,double x,double y,double vx,double vy, double g, double m, double xmin,double xmax,double ymin,double ymax)
{
	this->r = r;
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->g = g;
	this->m = m;
	this->xmin = xmin;
	this->xmax = xmax;
	this->ymin = ymin;
	this->ymax = ymax;
}

void Ball::step(double dt)
{
	double xp = x + vx * dt; // x position increases by velocity*time
	double yp = y + vy * dt - 0.5 * g * dt * dt; // y position increases by velocity*time minus 1/2 gravity*time^2
	// If the ball is within the x and y bounds, update the position and velocity as per above.
	// Otherwise, reverse the velocity (as it has to bounce off the wall, containing the same energy).
	if (xmin + r <= xp && xp <= xmax - r) { 
		x = xp ;
		// and vx remains the same
	} else {
		vx = -vx ;
	}
	if (ymin + r <= yp && yp <= ymax - r) { 
		y = yp ;
		vy = vy - g * dt; // velocity decreases by gravity times time
		// This is equivalent to saying (change in KE (m*vy^2)/2) = (m*g*vy*dt) = (change in GPE)
	} else { 
		vy = -vy ;
	}
} // so yes, energy is conserved

void Ball::display()
{
	// uses the standard library cout function to print out x and y for the ball, then flushes the output buffer with endl
	std::cout << x << " " << y << std::endl; 
}
