#include "Simulator.h"

Simulator::Simulator(HairStrand &strand) :m_strand{ &strand }
{

}

void Simulator::update()
{

}

void Simulator::addForce(const Force &_f)
{
  m_force += _f;
}

void Simulator::addForce(const ngl::Vec3 &_vec)
{
  m_force += Force(_vec);
}