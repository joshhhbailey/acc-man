#include <QtWidgets/QVBoxLayout>
#include <QtCore/QSignalMapper>

#include "PlatformContainer.h"

PlatformContainer::PlatformContainer()
{
    m_encrypter = new Encrypter();

    createPlatform("Steam");
    m_steamButton = createButton("Steam");

    createPlatform("League of Legends");
    m_lolButton = createButton("League of Legends");

    createConnections();
}

void PlatformContainer::createConnections()
{
    connect(m_steamButton, SIGNAL(clicked()), this, SLOT(steamButtonClicked()));
    connect(m_lolButton, SIGNAL(clicked()), this, SLOT(lolButtonClicked()));
}

void PlatformContainer::createPlatform(QString _platformName)
{
    // Create container to store accounts for platform
    AccountContainer* accountContainer = new AccountContainer(m_encrypter);
    m_accountContainers.insert(_platformName, accountContainer);

    // Add the account container to the mainLayout, but hide for now
    m_mainLayout->addWidget(m_accountContainers[_platformName]);
    m_accountContainers[_platformName]->hide();
}

QPushButton* PlatformContainer::createButton(QString _platformName)
{
    QPushButton* button = new QPushButton();
    button->setFixedHeight(95);
    QString iconPath = m_platformLogos[_platformName];
    button->setIcon(QIcon(":images/platform_icons/" + iconPath));
    button->setIconSize(QSize(60, 60));
    m_secondaryLayout->addWidget(button);
    return button;
}

void PlatformContainer::steamButtonClicked()
{
    m_accountContainers["League of Legends"]->hide();
    m_lolButton->setPalette(QPalette(Qt::darkGray));
    m_accountContainers["Steam"]->show();
    m_steamButton->setPalette(QPalette(QColor(45, 45, 45)));
}

void PlatformContainer::lolButtonClicked()
{
    m_accountContainers["Steam"]->hide();
    m_steamButton->setPalette(QPalette(Qt::darkGray));
    m_accountContainers["League of Legends"]->show();
    m_lolButton->setPalette(QPalette(QColor(45, 45, 45)));
}
