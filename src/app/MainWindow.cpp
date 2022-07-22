#include <QtWidgets/QMenuBar>
#include <QtGui/QColor>
#include <QtWidgets/QHBoxLayout>

#include "MainWindow.h"

MainWindow::MainWindow()
{
    setWindowTitle(tr("Account Manager"));
    setMinimumSize(512, 360);
    setMaximumSize(1024, 720);

    resize(1024, 720);

    createActions();
    createMenus();
    createWidgets();
    createLayouts();
    createConnections();
}

void MainWindow::createActions()
{
    m_aboutAction = new QAction("About");
}

void MainWindow::createMenus()
{
    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(tr("&Exit"), this, &QWidget::close);

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAction);
}

void MainWindow::createWidgets()
{
    m_mainWidget = new QWidget();
    setCentralWidget(m_mainWidget);

    m_aboutWidget = new AboutWidget();
    m_aboutWidget->setFixedSize(400, 600);

    m_platformContainer = new PlatformContainer();
    m_accountContainer = new AccountContainer();
}

void MainWindow::createLayouts()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(m_platformContainer);
    mainLayout->addWidget(m_accountContainer);
    m_mainWidget->setLayout(mainLayout);
}

void MainWindow::createConnections()
{
    connect(m_aboutAction, SIGNAL(triggered()), m_aboutWidget, SLOT(show()));
}

QPalette *MainWindow::darkPalette()
{
    QPalette *darkPalette = new QPalette();
    darkPalette->setColor(QPalette::Window, QColor(45, 45, 45));
    darkPalette->setColor(QPalette::WindowText, QColor(208, 208, 208));
    darkPalette->setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette->setColor(QPalette::AlternateBase, QColor(208, 208, 208));
    darkPalette->setColor(QPalette::ToolTipBase, QColor(208, 208, 208));
    darkPalette->setColor(QPalette::Text, QColor(208, 208, 208));
    darkPalette->setColor(QPalette::Button, QColor(45, 45, 45));
    darkPalette->setColor(QPalette::ButtonText, QColor(208, 208, 208));
    darkPalette->setColor(QPalette::BrightText, Qt::red);
    darkPalette->setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette->setColor(QPalette::Link, Qt::gray);
    return darkPalette;
}