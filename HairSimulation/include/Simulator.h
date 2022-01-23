#include <memory>
#include "HairStrand.h"
#include "Force.h"

class Simulator
{
public :
  Simulator(HairStrand &strand);
  void update();
  void addForce(const Force &);
  void addForce(const ngl::Vec3 &);
private:
  HairStrand *m_strand;
  Force m_force;
};