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
    m_scrollArea = new QScrollArea();
    m_mainWidget = new QWidget();
    m_createAccountButton = new QPushButton(tr("Create Account"));
}

void AccountContainer::createLayouts()
{
    m_mainLayout = new QVBoxLayout();
    m_accountsLayout = new QVBoxLayout();

    m_mainLayout->addWidget(m_scrollArea);
    m_scrollArea->setWidget(m_mainWidget);
    m_mainWidget->setLayout(m_accountsLayout);
    m_accountsLayout->addWidget(m_createAccountButton);

    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_accountsLayout->setAlignment(Qt::AlignTop);
    setLayout(m_mainLayout);
}

void AccountContainer::createConnections()
{
    connect(m_createAccountButton, SIGNAL(clicked()), this, SLOT(createAccountButtonClicked()));
}

void AccountContainer::createAccount()
{
    AccountWidget* accountWidget = new AccountWidget(m_currentAccounts);
    m_accountWidgets.push_back(accountWidget);
    m_accountsLayout->addWidget(accountWidget);
    m_currentAccounts++;
}

void AccountContainer::createAccountButtonClicked()
{
    if (m_currentAccounts < m_maxAccounts)
    {
        createAccount();
    }
}