#include <QtWidgets/QVBoxLayout>

#include "PlatformWidget.h"

PlatformWidget::PlatformWidget(QMap<QString, QString>& _platformLogos, QMap<QString, bool>& _activePlatforms, QString _platformName)
    : m_platformLogos(_platformLogos), m_activePlatforms(_activePlatforms), m_platformName(_platformName)
{
    setFixedHeight(120);

    createWidgets();
    createLayouts();
    createConnections();
}

void PlatformWidget::createWidgets()
{;
    m_mainButton = new QPushButton();
    m_mainButton->setFixedHeight(95);

    QString iconPath = m_platformLogos[m_platformName];
    m_mainButton->setIcon(QIcon(":images/platform_icons/" + iconPath));
    m_mainButton->setIconSize(QSize(60, 60));
    m_activePlatforms[m_platformName] = true;

    if (m_platformName == "League of Legends")
    {
        m_mainButton->setPalette(QPalette(Qt::darkGray));
        m_mainButton->setEnabled(false);
    }
}

void PlatformWidget::createLayouts()
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_mainButton);
    setLayout(mainLayout);
}

void PlatformWidget::createConnections()
{
    //
}

void PlatformWidget::mainButtonClicked()
{
    //
}
