#include <QtWidgets/QGridLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include "AccountWidget.h"

AccountWidget::AccountWidget(int& _currentAccounts) : m_currentAccounts(_currentAccounts)
{
    createWidgets();
    createLayouts();
    createConnections();

    setFixedHeight(120);
}

void AccountWidget::createWidgets()
{
    m_aliasLabel = new QLabel();
    m_aliasLabel->setText(tr("Alias:"));
    m_aliasLE = new QLineEdit(tr("New Account"));

    m_usernameLabel = new QLabel();
    m_usernameLabel->setText(tr("Username:"));
    m_usernameLE = new QLineEdit();

    m_passwordLabel = new QLabel();
    m_passwordLabel->setText(tr("Password:"));
    m_passwordLE = new QLineEdit();
    m_passwordLE->setEchoMode(QLineEdit::Password);

    m_loginButton = new QPushButton(tr("Login"));
    m_deleteButton = new QPushButton(tr("Delete"));
    m_saveButton = new QPushButton(tr("Save"));
}

void AccountWidget::createLayouts()
{
    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->addWidget(m_aliasLabel, 0, 0, 1, 1);
    mainLayout->addWidget(m_aliasLE, 1, 0, 1, 1);
    mainLayout->addWidget(m_usernameLabel, 0, 1, 1, 1);
    mainLayout->addWidget(m_usernameLE, 1, 1, 1, 1);
    mainLayout->addWidget(m_passwordLabel, 0, 2, 1, 1);
    mainLayout->addWidget(m_passwordLE, 1, 2, 1, 1);

    m_buttonsWidget = new QWidget();
    QVBoxLayout* buttonsLayout = new QVBoxLayout();
    buttonsLayout->addWidget(m_loginButton);
    buttonsLayout->addWidget(m_saveButton);
    buttonsLayout->addWidget(m_deleteButton);

    m_buttonsWidget->setLayout(buttonsLayout);
    mainLayout->addWidget(m_buttonsWidget, 0, 3, 3, 1);
    setLayout(mainLayout);
}

void AccountWidget::createConnections()
{
    connect(m_loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
    connect(m_saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
}

void AccountWidget::loginButtonClicked()
{
    // Write launch script
    QFile file("../../accounts/" + m_accountID.toString(QUuid::Id128) + ".bat");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out << "Stop-Process -Name \"Steam\"\n"
    "start \"\" \"C:\\Program Files (x86)\\Steam\\Steam.exe\" -login " << m_usernameLE->text() << " " << m_passwordLE->text();
}

void AccountWidget::saveButtonClicked()
{
    // Write saved details
    QFile file("../../accounts/" + m_accountID.toString(QUuid::Id128) + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out << m_aliasLE->text() << "\n" << m_usernameLE->text() << "\n" << m_passwordLE->text();
}

void AccountWidget::deleteButtonClicked()
{
    // Delete saved details
    if (QFile::exists("../../accounts/" + m_accountID.toString(QUuid::Id128) + ".txt"))
    {
        QFile::remove("../../accounts/" + m_accountID.toString(QUuid::Id128) + ".txt");
    }

    m_currentAccounts--;
    delete this;
}
