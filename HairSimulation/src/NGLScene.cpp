#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <iostream>

NGLScene::NGLScene(QWidget *_parent) :QOpenGLWidget(_parent)
{
  setFocusPolicy(Qt::StrongFocus);
}


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}



void NGLScene::resizeGL(int _w , int _h)
{
  m_win.width  = static_cast<int>( _w * devicePixelRatio() );
  m_win.height = static_cast<int>( _h * devicePixelRatio() );
}

const auto HairShader ="HairShader";

void NGLScene::initializeGL()
{
  // we must call that first before any other GL commands to load and link the
  // gl commands from the lib, if that is not done program will crash
  ngl::NGLInit::initialize();
  glClearColor(0.7f, 0.7f, 0.7f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);

  // initialize main camera
  m_mainCamera = std::make_unique<Camera>(CAMERA_EYE, CAMERA_CENTER, CAMERA_UP);

   ngl::ShaderLib::loadShader(HairShader, "shaders/HairVertex.glsl", "shaders/HairFragment.glsl");
   ngl::ShaderLib::use(HairShader);
  // startTimer(10);
   m_strand = std::make_unique<HairStrand>(10, 5.0f);

}



void NGLScene::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,m_win.width,m_win.height);

  m_strand->render(m_mainCamera->getViewMat(), m_mainCamera->getProjectMat());
  
}

//----------------------------------------------------------------------------------------------------------------------

void NGLScene::keyPressEvent(QKeyEvent *_event)
{ 
  //QOpenGLWidget::keyPressEvent(_event);
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
  // escape key to quite
  case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
  case Qt::Key_Space :
    m_win.spinXFace=0;
    m_win.spinYFace=0;
    m_modelPos.set(ngl::Vec3::zero());
    break;
  case Qt::Key_Alt:
    m_win.camera_mode = true;
    break;
  default : break;
  }
  // finally update the GLWindow and re-draw

    update();
}

void NGLScene::keyReleaseEvent(QKeyEvent *_event) 
{
  switch (_event->key())
  {
  case Qt::Key_Alt:
    m_win.camera_mode = false;
    break;

  default:
    break;
  }

    update();
}

void NGLScene::timerEvent(QTimerEvent *_timer)
{
   update();
}

void NGLScene::resetCamera()
{
  m_mainCamera->setCamera(CAMERA_EYE, CAMERA_CENTER, CAMERA_UP);
  update();
}
