#include <QtWidgets/QGridLayout>

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
    m_usernameLabel = new QLabel();
    m_usernameLabel->setText("Username:");

    m_passwordLabel = new QLabel();
    m_passwordLabel->setText("Password:");

    m_usernameLE = new QLineEdit();
    //m_usernameLE->setMaximumSize(1024, 100);

    m_passwordLE = new QLineEdit();
    //m_passwordLE->setMaximumSize(1024, 100);
    m_passwordLE->setEchoMode(QLineEdit::Password);

    m_loginButton = new QPushButton("Login");
    m_deleteButton = new QPushButton("Delete");
}

void AccountWidget::createLayouts()
{
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(m_usernameLabel, 0, 0, 1, 1);
    mainLayout->addWidget(m_usernameLE, 1, 0, 1, 1);
    mainLayout->addWidget(m_passwordLabel, 0, 1, 1, 1);
    mainLayout->addWidget(m_passwordLE, 1, 1, 1, 1);
    mainLayout->addWidget(m_loginButton, 0, 2, 1, 1);
    mainLayout->addWidget(m_deleteButton, 1, 2, 1, 1);
    setLayout(mainLayout);
}

void AccountWidget::createConnections()
{
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
}

void AccountWidget::loginButtonClicked()
{
    
}

void AccountWidget::deleteButtonClicked()
{
    delete this;
}
