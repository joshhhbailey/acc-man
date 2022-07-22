#include <QtWidgets/QVBoxLayout>

#include "AccountContainer.h"

AccountContainer::AccountContainer()
{
    setMinimumSize(384, 360);
    setMaximumSize(768, 720);

    createWidgets();
    createLayouts();
    createConnections();

    createAccount();
}

void AccountContainer::createWidgets()
{
    m_createAccountButton = new QPushButton("Create Account");
}

void AccountContainer::createLayouts()
{
    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addWidget(m_createAccountButton);
    m_mainLayout->setAlignment(Qt::AlignTop);
    setLayout(m_mainLayout);
}

void AccountContainer::createConnections()
{
    connect(m_createAccountButton, SIGNAL(clicked()), this, SLOT(createAccountButtonClicked()));
}

void AccountContainer::createAccount()
{
    AccountWidget* accountWidget = new AccountWidget();
    m_accountWidgets.push_back(accountWidget);
    m_mainLayout->addWidget(accountWidget);
}

void AccountContainer::createAccountButtonClicked()
{
    createAccount();
}