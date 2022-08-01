#ifndef ACCOUNTCONTAINER_H_
#define ACCOUNTCONTAINER_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtCore/QVector>

#include "AccountWidget.h"
#include "Encrypter.h"

class AccountContainer : public QGroupBox
{
    Q_OBJECT
public:
    AccountContainer();

public slots:
    void createAccountButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    void createAccount();
    void createAccount(QStringList _accountDetails);
    bool loadSavedAccounts();

    QVBoxLayout* m_mainLayout;
    QScrollArea* m_scrollArea;
    QWidget* m_mainWidget;
    QVBoxLayout* m_accountsLayout;

    QVector<AccountWidget*> m_accountWidgets;
    QPushButton* m_createAccountButton;

    int m_maxAccounts = 10;
    int m_currentAccounts = 0;

    Encrypter* m_encrypter;
};

#endif  // _ACCOUNTCONTAINER_H_