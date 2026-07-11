#include <iostream>
#include <math.h>
#include "Shapes.h"
using namespace std;

// CONSTANTS
const float PI = 3.14159f;

// Shape2D
void Shape2D::ShowArea() const
{
	// Each of these function is invoked by a Shape2D pointer (this)
	// Polymorphic behavior determines which specific version is called
	// If "this" is a Circle, call Circle::GetName2D() and Circle::Area()
	// If "this" is a Rectangle, call Rectangle:GetName2D(), etc…

	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator> (const Shape2D& rhs) const {
	return (this->Area() > rhs.Area());
}

bool Shape2D::operator< (const Shape2D& rhs) const {
	return (this->Area() < rhs.Area());
}

bool Shape2D::operator== (const Shape2D& rhs) const {
	return (this->Area() == rhs.Area());
}

// Shape3D
void Shape3D::ShowVolume() const
{
	// Each of these function is invoked by a Shape2D pointer (this)
	// Polymorphic behavior determines which specific version is called
	// If "this" is a Circle, call Circle::GetName2D() and Circle::Area()
	// If "this" is a Rectangle, call Rectangle:GetName2D(), etc…
	
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator> (const Shape3D& rhs) const {
	return (this->Volume() > rhs.Volume());
}

bool Shape3D::operator< (const Shape3D& rhs) const {
	return (this->Volume() < rhs.Volume());
}

bool Shape3D::operator== (const Shape3D& rhs) const {
	return (this->Volume() == rhs.Volume());
}

// Square
Square::Square(float sidelength)
{
	_sideLength = sidelength;
}

void Square::Scale(float scaleFactor)
{
	_sideLength *= scaleFactor;
}

void Square::Display() const {
	ShowArea();
	cout << "Length of a side: " << _sideLength << endl;
}

float Square::Area() const {
	return _sideLength * _sideLength;
}

string Square::GetName2D() const {
	return "Square";
}

// Triangle
Triangle::Triangle(float base, float height)
{
	_base = base;
	_height = height;
}

void Triangle::Scale(float scaleFactor)
{
	_base *= scaleFactor;
	_height *= scaleFactor;
}

void Triangle::Display() const {
	ShowArea();
	cout << "Base: " << _base << endl;
	cout << "Height: " << _height << endl;
}

float Triangle::Area() const {
	return (((1.0f / 2.0f)) * _base * _height);
}

string Triangle::GetName2D() const {
	return "Triangle";
}

// Circle
Circle::Circle(float radius)
{
	_radius = radius;
}

void Circle::Scale(float scaleFactor)
{
	_radius *= scaleFactor;
}

void Circle::Display() const {
	ShowArea();
	cout << "Radius: " << _radius << endl;
}

float Circle::Area() const {
	return (PI * (_radius * _radius));
}

string Circle::GetName2D() const {
	return "Circle";
}

// TriangularPyramid
TriangularPyramid::TriangularPyramid(float pyramidHeight, float triBase, float triHeight)
	: Triangle(triBase, triHeight)
{
	_pyramidHeight = pyramidHeight;
}

void TriangularPyramid::Scale(float scaleFactor)
{
	Triangle::Scale(scaleFactor);
	_pyramidHeight *= scaleFactor;
}

void TriangularPyramid::Display() const {
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The height is: " << _pyramidHeight << endl;
	Triangle::Display();
}

float TriangularPyramid::Volume() const {
	float area = Triangle::Area();
	return ((1.0f / 3.0f) * area * _pyramidHeight);
}

string TriangularPyramid::GetName3D() const {
	return "TriangularPyramid";
}

// Cylinder
Cylinder::Cylinder(float cylinderHeight, float cirRadius)
	: Circle(cirRadius)
{
	_cylinderHeight = cylinderHeight;
}

void Cylinder::Scale(float scaleFactor)
{
	Circle::Scale(scaleFactor);
	_cylinderHeight *= scaleFactor;
}

void Cylinder::Display() const {
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	cout << "The height is: " << _cylinderHeight << endl;
	Circle::Display();
}

float Cylinder::Volume() const {
	float area = Circle::Area();
	return (area * _cylinderHeight);
}

string Cylinder::GetName3D() const {
	return "Cylinder";
}

// Sphere
Sphere::Sphere(float cirRadius) 
	: Circle(cirRadius)
{
}

void Sphere::Scale(float scaleFactor)
{
	Circle::Scale(scaleFactor);
}

void Sphere::Display() const {
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
	Circle::Display();
}

float Sphere::Volume() const {
	float area = Circle::Area();
	float rSquared = area / PI;
	float r = sqrt(rSquared);

	return ((4.0f / 3.0f) * area * r);
}

string Sphere::GetName3D() const {
	return "Sphere";
}