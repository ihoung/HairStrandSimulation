#include "Camera.h"
#include <ngl/Util.h>

Camera::Camera(ngl::Vec3 _eye, ngl::Vec3 _center, ngl::Vec3 _up, float _fovy, float _aspect, float _zNear, float _zFar) :
  m_eye{ _eye }, m_center{ _center }, m_up{ _up }, m_fovy{ _fovy }, m_aspect{ _aspect }, m_zNear{ _zNear }, m_zFar{ _zFar }
{
  m_up.normalize();
  updateViewMat();
  m_project = ngl::perspective(m_fovy, m_aspect, m_zNear, m_zFar);
}

void Camera::updateViewMat()
{
  m_view = ngl::lookAt(m_eye, m_center, m_up);
}

ngl::Mat4 Camera::getViewMat() const
{
  return m_view;
}

ngl::Mat4 Camera::getProjectMat() const
{
  return m_project;
}

void Camera::translateCamera(ngl::Vec2 _diff)
{
  ngl::Vec3 right = (m_eye - m_center).cross(m_up);
  right.normalize();
  auto translation = _diff.m_x * right + _diff.m_y * m_up;
  m_eye += translation;
  m_center += translation;
  updateViewMat();
}

void Camera::spinCamera(ngl::Vec2 _diff)
{
  ngl::Mat4 rotX, rotY;
  rotX.rotateX(_diff.m_x);
  rotY.rotateY(_diff.m_y);
  auto rot = rotX * rotY;
  m_eye = rot * m_eye;
  auto up = (rot * ngl::Vec4(m_up, 0));
  m_up = ngl::Vec3{ up.m_x, up.m_y, up.m_z };
  updateViewMat();
}

void Camera::setCamera(ngl::Vec3 _eye, ngl::Vec3 _center, ngl::Vec3 _up, float _fovy, float _aspect, float _zNear, float _zFar)
{
  m_eye = _eye;
  m_center = _center;
  m_up = _up;
  m_up.normalize();
  m_fovy = _fovy;
  m_aspect = _aspect;
  m_zNear = _zNear;
  m_zFar = _zFar;
  updateViewMat();
  m_project = ngl::perspective(m_fovy, m_aspect, m_zNear, m_zFar);
}