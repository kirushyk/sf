/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"
#include "stdlib.h"

// Vector ==========================================

Vector::Vector()
{
	Set(0.f, 0.f);
}

Vector::Vector(float _x, float _y)
{
	Set(_x, _y);
}

Vector Vector::operator + (Vector _o)
{
	return Vector(x + _o.x, y + _o.y);
}

Vector Vector::operator - (Vector _o)
{
	return Vector(x - _o.x, y - _o.y);
}

Vector Vector::operator * (float _o)
{
	return Vector(x * _o, y * _o);
}

Vector Vector::operator * (uint32_t _o)
{
	return Vector(x * _o, y * _o);
}

/*Vector &Vector::operator += (Vector &_o)
{
  x += _o.x;
  y += _o.y;
  return *this;
}

Vector &Vector::operator -= (Vector &_o)
{
  x -= _o.x;
  y -= _o.y;
  return *this;
}

Vector &Vector::operator *= (float _o)
{
  x *= _o;
  y *= _o;
  return *this;
}*/

void Vector::Set(float _x, float _y)
{
	x = _x;
	y = _y;
}

void Vector::Polar(float _angle, float _radius)
{
	x = _radius * cos(_angle);
	y = _radius * sin(_angle);
}

float Vector::Length() const
{
	return sqrt(x * x + y * y);
}

float DotProduct(Vector &a, Vector &b)
{
	return a.x * b.x + a.y * b.y;
}

// Color ===========================================

Color::Color()
{
	Set(1.f, 1.f, 1.f, 1.f);
}

Color::Color(uint32_t _c)
{
	Set(_c);
}

Color::Color(float _a, float _r, float _g, float _b)
{
	Set(_a, _r, _g, _b);
}

uint32_t Color::Get() const
{
	return (static_cast<uint32_t>(a * 255.f) << 24)
	     | (static_cast<uint32_t>(r * 255.f) << 16)
	     | (static_cast<uint32_t>(g * 255.f) << 8)
	     |  static_cast<uint32_t>(b * 255.f);
}

void Color::Set(uint32_t _c)
{
	a = ((_c & 0xff000000) >> 24) / 255.f;
	r = ((_c & 0x00ff0000) >> 16) / 255.f;
	g = ((_c & 0x0000ff00) >> 8)  / 255.f;
	b = ( _c & 0x000000ff)        / 255.f;
	return;
}

void Color::Set(float _a, float _r, float _g, float _b)
{
	a = _a;
	r = _r;
	g = _g;
	b = _b;
}

Color InterpolateColors(Color A, Color B, float Scalar)
{
	return Color(A.r + Scalar*(B.r - A.r), A.g + Scalar*(B.g - A.g), A.b + Scalar*(B.b - A.b), A.a + Scalar*(B.a - A.a));
}

float frand(float min, float max)
{
	return min + rand()*(max - min)/RAND_MAX;
}
