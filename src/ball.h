/** file: ball.h
 ** brief: Ball class
 ** author: Andrea Vedaldi
 **/

#ifndef __ball__
#define __ball__

#include "simulation.h"

class Ball : public Simulation
{
public:
  // Constructors and member functions
  Ball() ;
  // new constructor to allow for different initial conditions:
  Ball(double r, double x, double y, double vx, double vy, double g, double m, double xmin, double xmax, double ymin, double ymax);
  void step(double dt) ;
  void display() ;

  // Add getter and setter functions for the ball's position and velocity
  double getX() { return x; }
  double getY() { return y; }
  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }

protected:
  // Data members
  // We choose to hide these from public interface. Then, if we were e.g. to move to a different coordinate system
  // for the calculations (such as polar), users of the class would not have to concern themselves with this change.
  // 
  // Position and velocity of the ball
  double x ;
  double y ;
  double vx ;
  double vy ;

  // Mass and size of the ball
  double m ;
  double r ;

  // Gravity acceleration
  double g ;

  // Geometry of the box containing the ball
  double xmin ;
  double xmax ;
  double ymin ;
  double ymax ;
} ;

#endif /* defined(__ball__) */
