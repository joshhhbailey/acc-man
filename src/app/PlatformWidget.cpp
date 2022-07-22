#include <QtWidgets/QGridLayout>

#include "PlatformWidget.h"

PlatformWidget::PlatformWidget()
{
    createWidgets();
    createLayouts();
    createConnections();
}

void PlatformWidget::createWidgets()
{
    m_platformLabel = new QLabel();
    m_platformLabel->setText("Platforms");

    m_newButton = new QPushButton("New");
    m_deleteButton = new QPushButton("Delete");
}

void PlatformWidget::createLayouts()
{
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(m_platformLabel, 0, 0, 1, 1);
    mainLayout->addWidget(m_newButton, 3, 0, 1, 1);
    mainLayout->addWidget(m_deleteButton, 3, 1, 1, 1);
    setLayout(mainLayout);
}

void PlatformWidget::createConnections()
{
    //connect(m_compileButton, SIGNAL(clicked()), this, SLOT(compileButtonClicked()));
    //connect(m_pauseButton, SIGNAL(clicked()), this, SLOT(pauseButtonClicked()));
    //connect(m_libraryButton, SIGNAL(clicked()), this, SLOT(libraryButtonClicked()));
}

void PlatformWidget::newButtonClicked()
{

}

void PlatformWidget::deleteButtonClicked()
{

}
