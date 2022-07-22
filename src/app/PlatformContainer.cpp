#include <QtWidgets/QVBoxLayout>

#include "PlatformContainer.h"

PlatformContainer::PlatformContainer()
{
    setMinimumSize(128, 360);
    setMaximumSize(256, 720);

    createWidgets();
    createLayouts();
}

void PlatformContainer::createWidgets()
{
    m_platformWidget = new PlatformWidget();
}

void PlatformContainer::createLayouts()
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_platformWidget);
    setLayout(mainLayout);
}