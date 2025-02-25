/** file: graphics.h
 ** brief: Graphics helpers
 ** author: Andrea Vedaldi
 **/

#ifndef __graphics__
#define __graphics__

 // System headers first
#ifdef _WIN32
#include <windows.h>
#endif

// Standard C++ headers
#include <string>
#include <vector>

// OpenGL headers with platform-specific includes
#if defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

// Local headers last
#include "simulation.h"

// Forward declarations
class Drawable;
class Figure;

void run() ;
void run(Simulation * simulation, double timeStep) ;

/* ---------------------------------------------------------------- */
// class Drawable
/* ---------------------------------------------------------------- */

class Drawable {
public:
  virtual void draw() ;
} ;

/* ---------------------------------------------------------------- */
// class Figure
/* ---------------------------------------------------------------- */

class Figure : public Drawable
{
public:
  Figure(std::string name) ;
  ~Figure() ;

  void addDrawable(Drawable * object) ;
  void removeDrawables(Drawable * object) ;

  void update() const ;
  void reshape(int width, int height) ;
  void draw() ;

  void drawString(double x, double y, std::string str) ;
  void drawCircle(double x, double y, double radius) ;
  void drawLine(double x1, double y1, double x2, double y2, double thickness) ;

private:
  int id ;
  int windowWidth ;
  int windowHeight ;
  double pixelSize ;
  double xmin ;
  double xmax ;
  double ymin ;
  double ymax ;
  GLuint glGrid ;
  GLuint glCircle ;

  typedef std::vector<Drawable*> objects_t ;
  objects_t objects ;

  static void handleDisplay() ;
  static void handleReshape(int width, int heigh) ;
  static Figure * findByWindowId(int id) ;
  void updateGrid() ;
  void makeCurrent() const ;
} ;

#endif /* defined(__graphics__) */
