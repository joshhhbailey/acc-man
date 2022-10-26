#include <QtWidgets/QVBoxLayout>

#include "Container.h"

Container::Container()
{
    createWidgets();
    createLayouts();
}

void Container::createWidgets()
{
    m_scrollArea = new QScrollArea();
    m_mainWidget = new QWidget();
}

void Container::createLayouts()
{
    m_mainLayout = new QVBoxLayout();
    m_secondaryLayout = new QVBoxLayout();

    m_mainLayout->addWidget(m_scrollArea);
    m_scrollArea->setWidget(m_mainWidget);
    m_mainWidget->setLayout(m_secondaryLayout);

    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_secondaryLayout->setAlignment(Qt::AlignTop);
    setLayout(m_mainLayout);
}

void Container::createConnections()
{
    // No implementation required
}

void Container::createButtonClicked()
{
    // No implementation required
}
