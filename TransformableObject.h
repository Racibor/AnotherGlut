#pragma once
#include "Point3D.h"

class TransformableObject
{
public:
      void virtual translate(Point3D t) = 0;
      void virtual rotate() = 0;
      void virtual scale() = 0;
};

