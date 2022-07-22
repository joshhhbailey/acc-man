#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QtGui/QPalette>

#include "AccountContainer.h"
#include "PlatformContainer.h"
#include "AboutWidget.h"

class MainWindow : public QMainWindow
{
public:
    MainWindow();
    static QPalette *darkPalette();

private:
    void createActions();
    void createMenus();
    void createWidgets();
    void createLayouts();
    void createConnections();

    // Menus
    QMenu* m_fileMenu;
    QMenu* m_helpMenu;

    // Actions
    QAction* m_aboutAction;
    QActionGroup* alignmentGroup;

    // Widgets
    QWidget* m_mainWidget;
    AboutWidget* m_aboutWidget;

    // Containers
    PlatformContainer* m_platformContainer;
    AccountContainer* m_accountContainer;
};

#endif  // _MAINWINDOW_H_