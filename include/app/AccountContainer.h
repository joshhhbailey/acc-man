#ifndef ACCOUNTCONTAINER_H_
#define ACCOUNTCONTAINER_H_

#include <QtWidgets/QGroupBox>
#include <QtCore/QVector>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

#include "AccountWidget.h"

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

    QVector<AccountWidget*> m_accountWidgets;

    QVBoxLayout* m_mainLayout;

    QPushButton* m_createAccountButton;
};

#endif  // _ACCOUNTCONTAINER_H_