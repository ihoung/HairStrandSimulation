#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <ngl/Vec3.h>
#include <ngl/Vec3.h>
#include <ngl/Mat4.h>
#include "HairStrand.h"
#include "Camera.h"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(HairStrand, render)
{
//  HairStrand strand = HairStrand(10,5.0f);
//  auto p = strand.getPoint(2);
//  ASSERT_EQ(p.pos.m_y, 2.0f);
}

TEST(Camera, userCtor)
{
  //Camera c = Camera({ 0,0,10 }, { 0,0,0 }, { 0,1,0 });
  //ngl::Mat4 vp = c.getVPMat();
  //ngl::Mat4 res = ngl::lookAt({ 0,0,10 }, { 0,0,0 }, { 0,1,0 }) * ngl::perspective(45.0f, 1.0f, 0.1f, 200.0f);
  //ASSERT_EQ(vp, res);
}
