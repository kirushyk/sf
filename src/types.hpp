/*
 * (c) 2009, Kyrylo Polezhaiev
 *
 * types.hpp:
 *
 */

#pragma once

#include <stdint.h>

typedef struct Vector
{
  float       x,
              y;
              Vector();
              Vector(float _x, float _y);
  void        Set(float _x, float _y);
  void        Polar(float _angle, float _radius);
  float       Length() const;
  Vector      operator + (Vector _o);
  Vector      operator - (Vector _o);
  Vector      operator * (float _o);
  Vector      operator * (uint32_t _o);
} *PVector;

float DotProduct(Vector &, Vector &);

struct Color
{
  float       a,
              r,
              g,
              b;
              Color();
              Color(uint32_t _c);
              Color(float _a, float _r, float _g, float _b);
  uint32_t    Get() const;
  void        Set(uint32_t _c);
  void        Set(float _a, float _r, float _g, float _b);
};

Color InterpolateColors(Color A, Color B, float Scalar);

float frand(float min, float max);
