#ifndef HAIRSTRAND_H_
#define HAIRSTRAND_H_

#include <vector>
#include <memory>
#include <ngl/SimpleIndexVAO.h>
#include <ngl/Mat4.h>
#include "Particle.h"

class HairStrand
{
public:
  HairStrand() = default;
  HairStrand(const HairStrand &) = default;
  HairStrand(size_t _numParticles, float _totalLength);
  void render(ngl::Mat4 _view, ngl::Mat4 _project) const;
  //Particle getPoint(int _index) const;

private:
  std::size_t m_numParticles;
  float m_length;
  std::vector<Particle> m_points;
  std::unique_ptr<ngl::AbstractVAO> m_vao;
  std::vector<std::uint32_t> m_indexes;
};

#endif
