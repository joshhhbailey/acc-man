#include <QtWidgets/QGridLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include "AccountWidget.h"

AccountWidget::AccountWidget()
{
    createWidgets();
    createLayouts();
    createConnections();

    setMaximumSize(1024, 200);
}

void AccountWidget::createWidgets()
{
    m_aliasLabel = new QLabel();
    m_aliasLabel->setText("Alias:");
    m_aliasLE = new QLineEdit("New Account");

    m_usernameLabel = new QLabel();
    m_usernameLabel->setText("Username:");
    m_usernameLE = new QLineEdit();

    m_passwordLabel = new QLabel();
    m_passwordLabel->setText("Password:");
    m_passwordLE = new QLineEdit();
    m_passwordLE->setEchoMode(QLineEdit::Password);

    m_loginButton = new QPushButton("Login");
    m_deleteButton = new QPushButton("Delete");
}

void AccountWidget::createLayouts()
{
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(m_aliasLabel, 0, 0, 1, 1);
    mainLayout->addWidget(m_aliasLE, 1, 0, 1, 1);
    mainLayout->addWidget(m_usernameLabel, 0, 1, 1, 1);
    mainLayout->addWidget(m_usernameLE, 1, 1, 1, 1);
    mainLayout->addWidget(m_passwordLabel, 0, 2, 1, 1);
    mainLayout->addWidget(m_passwordLE, 1, 2, 1, 1);
    mainLayout->addWidget(m_loginButton, 0, 3, 1, 1);
    mainLayout->addWidget(m_deleteButton, 1, 3, 1, 1);
    setLayout(mainLayout);
}

void AccountWidget::createConnections()
{
    connect(m_loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
}

void AccountWidget::loginButtonClicked()
{
    QFile file("../../accounts/" + m_aliasLE->text() + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out << "Stop-Process -Name \"Steam\"\n"
    "start \"\" \"C:\\Program Files (x86)\\Steam\\Steam.exe\" -login " << m_usernameLE->text() << " " << m_passwordLE->text();
}

void AccountWidget::deleteButtonClicked()
{
    delete this;
}
