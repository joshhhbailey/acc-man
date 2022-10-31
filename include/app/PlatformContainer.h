#ifndef PLATFORMCONTAINER_H_
#define PLATFORMCONTAINER_H_

#include <QtCore/QMap>

#include <QtWidgets/QPushButton>

#include <AccountContainer.h>
#include "Container.h"

class PlatformContainer : public Container
{
    Q_OBJECT
public:
    PlatformContainer();

public slots:
    void steamButtonClicked();
    void lolButtonClicked();

private:
    void createConnections();
    void createPlatform(QString _platformName);
    QPushButton* createButton(QString _platformName);

    // Platform buttons
    QPushButton* m_steamButton;
    QPushButton* m_lolButton;
    
    QMap<QString, AccountContainer*> m_accountContainers;
    QMap<QString, QString> m_platformLogos = {{"Steam", "steam_icon.png"},
                                              {"League of Legends", "lol_icon.png"},
                                             };
};

#endif  // _PLATFORMCONTAINER_H_
