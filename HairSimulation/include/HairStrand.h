#ifndef HAIRSTRAND_H_
#define HAIRSTRAND_H_

#include <vector>
#include <memory>
#include <ngl/SimpleIndexVAO.h>
#include "Particle.h"

class HairStrand
{
public:
  HairStrand() = default;
  HairStrand(const HairStrand &) = default;
  HairStrand(size_t _numParticles, float _totalLength);
  void render() const;
  //Particle getPoint(int _index) const;

private:
  std::size_t m_numParticles;
  std::vector<Particle> m_points;
  std::unique_ptr<ngl::AbstractVAO> m_vao;
  std::vector<std::uint32_t> m_indexes;
};

#endif
