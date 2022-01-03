#include "MainWindow.h"
#include "ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  m_gl = new NGLScene(this);
  ui->m_mainWndGridLayout->addWidget(m_gl, 0, 0, 4, 4);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete m_gl;
}

