#include "MainWindow.h"
#include "ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  m_gl = new NGLScene(this);
  ui->m_mainWndGridLayout->addWidget(m_gl, 0, 0, 4, 4);

  connectUI();
}

MainWindow::~MainWindow()
{
  delete ui;
  delete m_gl;
}

void MainWindow::connectUI()
{
  connect(ui->m_resetCamera, SIGNAL(clicked()), m_gl, SLOT(resetCamera()));
}

