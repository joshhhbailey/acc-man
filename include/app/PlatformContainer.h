#ifndef PLATFORMCONTAINER_H_
#define PLATFORMCONTAINER_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtCore/QVector>
#include <QtCore/QMap>

#include "PlatformWidget.h"

class PlatformContainer : public QGroupBox
{
    Q_OBJECT
public:
    PlatformContainer();

public slots:
    void createPlatformButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    void createPlatform(QString _platformName);

    QVBoxLayout* m_mainLayout;
    QScrollArea* m_scrollArea;
    QWidget* m_mainWidget;
    QVBoxLayout* m_platformsLayout;

    QVector<PlatformWidget*> m_platformWidgets;
    QPushButton* m_createPlatformButton;

    QMap<QString, QString> m_platformLogos = {{"Steam", "steam_icon.png"},
                                              {"League of Legends", "lol_icon.png"},
                                             };

    QMap<QString, bool> m_activePlatforms = {{"Steam", false},
                                             {"League of Legends", false}
                                            };
};

#endif  // _PLATFORMCONTAINER_H_