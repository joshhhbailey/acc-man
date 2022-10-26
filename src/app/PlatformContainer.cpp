#include <QtWidgets/QVBoxLayout>

#include "PlatformContainer.h"

PlatformContainer::PlatformContainer()
{
    setFixedWidth(256);

    m_createButton = new QPushButton(tr("Create Platform"));
    m_createButton->setPalette(QPalette(Qt::darkGray));
    m_createButton->setEnabled(false);
    m_secondaryLayout->addWidget(m_createButton);

    createConnections();
    createPlatform("Steam");
    createPlatform("League of Legends");
}

void PlatformContainer::createConnections()
{
    //
}

void PlatformContainer::createPlatform(QString _platformName)
{
    PlatformWidget* platformWidget = new PlatformWidget(m_platformLogos, _platformName);
    m_platformWidgets.push_back(platformWidget);
    m_secondaryLayout->addWidget(platformWidget);
    m_activePlatforms[_platformName] = true;
}

void PlatformContainer::createButtonClicked()
{
    //
}
