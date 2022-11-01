#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDirIterator>
#include <QtCore/QDir>

#include "AccountContainer.h"

AccountContainer::AccountContainer(Encrypter* _encrypter) :
    m_encrypter(_encrypter)
{
    setFixedWidth(768);

    createWidgets();
    createLayouts();
    createConnections();

    if (!QDir("accounts").exists())
    {
        QDir().mkdir("../accounts");
    }

    if (!loadSavedAccounts())
    {
        // No saved accounts loaded
        createAccount();
    }
}

void AccountContainer::createWidgets()
{
    m_createButton = new QPushButton();
    m_createButton->setText(tr("Create Account"));
}

void AccountContainer::createLayouts()
{
    m_secondaryLayout->addWidget(m_createButton);
}

void AccountContainer::createConnections()
{
    connect(m_createButton, SIGNAL(clicked()), this, SLOT(createButtonClicked()));
}

void AccountContainer::createAccount()
{
    AccountWidget* accountWidget = new AccountWidget(m_currentAccounts, m_encrypter);
    m_accountWidgets.push_back(accountWidget);
    m_secondaryLayout->addWidget(accountWidget);
    m_currentAccounts++;
}

void AccountContainer::createAccount(QStringList _accountDetails)
{
    AccountWidget* accountWidget = new AccountWidget(m_currentAccounts, _accountDetails, m_encrypter);
    m_accountWidgets.push_back(accountWidget);
    m_secondaryLayout->addWidget(accountWidget);
    m_currentAccounts++;
}

bool AccountContainer::loadSavedAccounts()
{
    // Check directory contains files
    if (!QDir("../accounts").exists() || QDir("../accounts").isEmpty())
    {
        return false;
    }

    // Iterate through all saved accounts
    QStringList files = QDir("../accounts").entryList(QDir::Files);
    foreach (const QString &fileName, files)
    {
        QFile file("../accounts/" + fileName);
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

void AccountContainer::createButtonClicked()
{
    if (m_currentAccounts < m_maxAccounts)
    {
        createAccount();
    }
}
