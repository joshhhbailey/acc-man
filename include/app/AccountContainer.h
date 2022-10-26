#ifndef ACCOUNTCONTAINER_H_
#define ACCOUNTCONTAINER_H_

#include <QtCore/QVector>

#include "AccountWidget.h"
#include "Container.h"
#include "Encrypter.h"

class AccountContainer : public Container
{
    Q_OBJECT
public:
    AccountContainer();

public slots:
    void createButtonClicked();

private:
    void createConnections();

    void createAccount();
    void createAccount(QStringList _accountDetails);
    bool loadSavedAccounts();

    QVector<AccountWidget*> m_accountWidgets;

    int m_maxAccounts = 10;
    int m_currentAccounts = 0;

    Encrypter* m_encrypter;
};

#endif  // _ACCOUNTCONTAINER_H_
