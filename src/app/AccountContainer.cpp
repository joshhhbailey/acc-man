#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDirIterator>

#include "AccountContainer.h"

AccountContainer::AccountContainer()
{
    m_encrypter = new Encrypter();

    setMinimumSize(384, 360);
    setMaximumSize(768, 720);

    createWidgets();
    createLayouts();
    createConnections();

    if (!loadSavedAccounts())
    {
        // No saved accounts loaded
        createAccount();
    }
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
    AccountWidget* accountWidget = new AccountWidget(m_currentAccounts, m_encrypter);
    m_accountWidgets.push_back(accountWidget);
    m_accountsLayout->addWidget(accountWidget);
    m_currentAccounts++;
}

void AccountContainer::createAccount(QStringList _accountDetails)
{
    AccountWidget* accountWidget = new AccountWidget(m_currentAccounts, _accountDetails, m_encrypter);
    m_accountWidgets.push_back(accountWidget);
    m_accountsLayout->addWidget(accountWidget);
    m_currentAccounts++;
}

bool AccountContainer::loadSavedAccounts()
{
    // Check directory contains files
    if (QDir("../../accounts").isEmpty())
    {
        return false;
    }

    // Iterate through all saved accounts
    QStringList files = QDir("../../accounts").entryList(QDir::Files);
    foreach (const QString &fileName, files)
    {
        QFile file("../../accounts/" + fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }

        // Extract account details
        QStringList accountDetails;
        accountDetails.append(QFileInfo(file).baseName());
        QTextStream in(&file);
        while(!in.atEnd())
        {
            accountDetails.append(in.readLine());
        }
        createAccount(accountDetails);
    }
    return true;
}

void AccountContainer::createAccountButtonClicked()
{
    if (m_currentAccounts < m_maxAccounts)
    {
        createAccount();
    }
}