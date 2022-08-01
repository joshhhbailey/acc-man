#include <QtWidgets/QVBoxLayout>

#include "PlatformContainer.h"

PlatformContainer::PlatformContainer()
{
    setMinimumSize(128, 360);
    setMaximumSize(256, 720);

    createWidgets();
    createLayouts();
    createConnections();

    createPlatform("Steam");
    createPlatform("League of Legends");
}

void PlatformContainer::createWidgets()
{
    m_scrollArea = new QScrollArea();
    m_mainWidget = new QWidget();

    m_createPlatformButton = new QPushButton(tr("Create Platform"));
    m_createPlatformButton->setPalette(QPalette(Qt::darkGray));
    m_createPlatformButton->setEnabled(false);
}

void PlatformContainer::createLayouts()
{
    m_mainLayout = new QVBoxLayout();
    m_platformsLayout = new QVBoxLayout();

    m_mainLayout->addWidget(m_scrollArea);
    m_scrollArea->setWidget(m_mainWidget);
    m_mainWidget->setLayout(m_platformsLayout);
    m_platformsLayout->addWidget(m_createPlatformButton);

    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_platformsLayout->setAlignment(Qt::AlignTop);
    setLayout(m_mainLayout);
}

void PlatformContainer::createConnections()
{
    //
}

void PlatformContainer::createPlatform(QString _platformName)
{
    PlatformWidget* platformWidget = new PlatformWidget(m_platformLogos, m_activePlatforms, _platformName);
    m_platformWidgets.push_back(platformWidget);
    m_platformsLayout->addWidget(platformWidget);
}

void PlatformContainer::createPlatformButtonClicked()
{
    //
}
