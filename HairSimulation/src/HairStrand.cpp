#include "HairStrand.h"
#include <ngl/Transformation.h>
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/Util.h>
#include <ngl/VAOFactory.h>

HairStrand::HairStrand(std::size_t _numParticles, float totalLength)
{
  m_numParticles = _numParticles;

  float curPosY = 0.0f;
  float pDistance = totalLength / (float)_numParticles;
  for (std::uint32_t i = 0; i < _numParticles; ++i)
  {
	m_points.push_back(Particle({ 0, curPosY, 0 }));
	curPosY += pDistance;

	if (i != _numParticles - 1)
	{
	  m_indexes.push_back(i);
	  m_indexes.push_back(i + 1);
	}
  }
  m_vao = ngl::VAOFactory::createVAO(ngl::simpleIndexVAO, GL_LINES);
}

void HairStrand::render() const
{
  auto view = ngl::lookAt({ 5,15,25 }, { 0,0,0 }, { 0,1,0 });
  auto project = ngl::perspective(45.0f, 1.0f, 0.1f, 200.0f);
  ngl::ShaderLib::setUniform("MVP", project * view);
  glPointSize(3);
  m_vao->bind();
  m_vao->setData(ngl::SimpleIndexVAO::VertexData(m_numParticles * sizeof(ngl::Vec3), m_points[0].pos.m_x, sizeof(m_indexes), &m_indexes[0], GL_UNSIGNED_INT));
  m_vao->setVertexAttributePointer(0, 3, GL_FLOAT, sizeof(Particle), 0);
  m_vao->setNumIndices(m_numParticles);
  glEnable(GL_PROGRAM_POINT_SIZE);
  m_vao->draw();
  glDisable(GL_PROGRAM_POINT_SIZE);
  m_vao->unbind();
}

//Particle HairStrand::getPoint(int _index) const
//{
//  return m_points[_index];
//}