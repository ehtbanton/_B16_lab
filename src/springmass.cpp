/** file: springmass.cpp
 ** brief: SpringMass simulation implementation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

#include <iostream>

 /* ---------------------------------------------------------------- */
 // class Mass
 /* ---------------------------------------------------------------- */

Mass::Mass()
	: position(), velocity(), force(), mass(1), radius(1),
	xmin(-1), xmax(1), ymin(-1), ymax(1)
{
}

Mass::Mass(Vector2 position, Vector2 velocity, double mass, double radius)
	: position(position), velocity(velocity), force(), mass(mass), radius(radius),
	xmin(-1), xmax(1), ymin(-1), ymax(1)
{
}

void Mass::setForce(Vector2 f)
{
	force = f;
}

void Mass::addForce(Vector2 f)
{
	force = force + f;
}

Vector2 Mass::getForce() const
{
	return force;
}

Vector2 Mass::getPosition() const
{
	return position;
}

Vector2 Mass::getVelocity() const
{
	return velocity;
}

double Mass::getRadius() const
{
	return radius;
}

double Mass::getMass() const
{
	return mass;
}

double Mass::getEnergy(double gravity) const
{
	/* INCOMPLETE: TYPE YOUR CODE HERE */
	double kinetic = 0.5 * mass * velocity.norm2();
	double potential = mass * gravity * position.y;

	double energy = kinetic + potential;
	return energy;
}

void Mass::step(double dt)
{
	/* INCOMPLETE: TYPE YOUR CODE HERE */

	Vector2 new_pos = position + velocity * dt + 0.5 * force * dt * dt/mass; // position increases by velocity*time and due to force 
	
	if (xmin + radius <= new_pos.x && new_pos.x <= xmax - radius) {
		position.x = new_pos.x;
		velocity.x = velocity.x + force.x * dt / mass;
	}
	else {
		velocity.x = -velocity.x;
	}
	if (ymin + radius <= new_pos.y && new_pos.y <= ymax - radius) {
		position.y = new_pos.y;
		velocity.y = velocity.y + force.y * dt / mass;
		velocity.y += EARTH_GRAVITY * dt;
	}
	else {
		velocity.y = -velocity.y;
	}
}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring()
	: mass1(nullptr),
	mass2(nullptr),
	naturalLength(1.0),
	stiffness(1.0),
	damping(0.01)
{
}

Spring::Spring(Mass* mass1, Mass* mass2, double naturalLength, double stiffness, double damping)
	: mass1(mass1), mass2(mass2),
	naturalLength(naturalLength), stiffness(stiffness), damping(damping)
{
}

Mass* Spring::getMass1() const
{
	return mass1;
}

Mass* Spring::getMass2() const
{
	return mass2;
}

Vector2 Spring::getForce() const
{
	Vector2 F;
	Vector2 displacement = mass2->getPosition() - mass1->getPosition();
	double currentLength = getLength();
	Vector2 unitVector = displacement * (1.0 / currentLength);
	double extension = currentLength - naturalLength;
	Vector2 springForce = unitVector * (-stiffness * extension);
	Vector2 relativeVelocity = mass2->getVelocity() - mass1->getVelocity();
	Vector2 dampingForce = relativeVelocity * (-damping);

	F = springForce + dampingForce;
	return F;
}

double Spring::getLength() const
{
	Vector2 u = mass2->getPosition() - mass1->getPosition();
	return u.norm();
}

double Spring::getEnergy() const {
	double length = getLength();
	double dl = length - naturalLength;
	return 0.5 * stiffness * dl * dl;
}

std::ostream& operator << (std::ostream& os, const Mass& m)
{
	os << "("
		<< m.getPosition().x << ","
		<< m.getPosition().y << ")";
	return os;
}

std::ostream& operator << (std::ostream& os, const Spring& s)
{
	return os << "$" << s.getLength();
}

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

// Default constructor
SpringMass::SpringMass()
	: gravity(MOON_GRAVITY),
	mass1(),  // Uses Mass default constructor
	mass2(),  // Uses Mass default constructor
	spring()  // Uses Spring default constructor
{
}

// Modified constructor with spring parameter
SpringMass::SpringMass(Spring spring, double gravity)
	: gravity(gravity),
	mass1(*spring.getMass1()),
	mass2(*spring.getMass2())
{
	// Create a new spring that points to our copies of the masses
	this->spring = Spring(&this->mass1, &this->mass2,
		spring.getNaturalLength(),
		1.0,   // stiffness
		1.0);  // damping
}

void SpringMass::display()
{
	Vector2 mass1pos = mass1.getPosition();
	Vector2 mass2pos = mass2.getPosition();
	std::cout << "\n" << mass1.getPosition().x << "," << mass1.getPosition().y <<
		"\n" << mass2.getPosition().x << "," << mass2.getPosition().y << std::endl;
}

double SpringMass::getEnergy() const
{
	double energy = 0;

	energy += mass1.getEnergy(gravity);
	energy += mass2.getEnergy(gravity);
	energy += spring.getEnergy();

	return energy;
}

void SpringMass::step(double dt)
{
	Vector2 g(0, -gravity);

	mass1.setForce(g);
	mass2.setForce(g);
	Vector2 force = spring.getForce();
	Vector2 zero;
	mass1.addForce(zero - force);
	mass2.addForce(force);

	mass1.step(dt);
	mass2.step(dt);

}


/* INCOMPLETE: TYPE YOUR CODE HERE */


