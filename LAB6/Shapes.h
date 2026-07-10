#pragma once
#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape() {}
};

class Shape2D : virtual public Shape
{
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator> (const Shape2D& rhs) const;
	bool operator< (const Shape2D& rhs) const;
	bool operator== (const Shape2D& rhs) const;
	virtual ~Shape2D() {}
};

class Shape3D : virtual public Shape
{
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator> (const Shape3D & rhs) const;
	bool operator< (const Shape3D & rhs) const;
	bool operator== (const Shape3D & rhs) const;
	virtual ~Shape3D() {}
};

class Square : public Shape2D
{
	float _sideLength;
public:
	Square(float sideLength = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Triangle : public Shape2D
{
	float _base;
	float _height;
public:
	Triangle(float base = 0, float height = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Circle : public Shape2D
{
	float _radius;
public:
	Circle(float radius = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class TriangularPyramid : public Shape3D, private Triangle
{
	float _pyramidHeight;
public:
	TriangularPyramid(float pyramidHeight = 0, float triBase = 0, float triHeight = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Cylinder : public Shape3D, private Circle
{
	float _cylinderHeight;
public:
	Cylinder(float cylinderHeight = 0, float cirRadius = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Sphere : public Shape3D, private Circle
{
public:
	Sphere(float cirRadius = 0);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};