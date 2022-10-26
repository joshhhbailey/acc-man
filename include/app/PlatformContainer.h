#ifndef PLATFORMCONTAINER_H_
#define PLATFORMCONTAINER_H_

#include <QtCore/QVector>
#include <QtCore/QMap>

#include "Container.h"
#include "PlatformWidget.h"

class PlatformContainer : public Container
{
    Q_OBJECT
public:
    PlatformContainer();

public slots:
    void createButtonClicked();

private:
    void createConnections();
    void createPlatform(QString _platformName);

    QVector<PlatformWidget*> m_platformWidgets;

    QMap<QString, QString> m_platformLogos = {{"Steam", "steam_icon.png"},
                                              {"League of Legends", "lol_icon.png"},
                                             };

    QMap<QString, bool> m_activePlatforms = {{"Steam", false},
                                             {"League of Legends", false}
                                            };
};

#endif  // _PLATFORMCONTAINER_H_
