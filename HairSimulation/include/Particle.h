#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <ngl/Vec3.h>

struct Particle
{
  Particle() = default;
  Particle(const Particle &) = default;
  Particle(const ngl::Vec3 &_pos) : pos(_pos) {}
  ngl::Vec3 pos;
};

#endif