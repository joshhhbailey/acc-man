#include <QtWidgets/QGridLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include "AccountWidget.h"

AccountWidget::AccountWidget(int& _currentAccounts, Encrypter* _encrypter)
    : m_currentAccounts(_currentAccounts), m_encrypter(_encrypter)
{
    m_accountID = QUuid::createUuid();
    createWidgets();
    createLayouts();
    createConnections();
    setFixedHeight(120);

    m_saveButton->setPalette(QPalette(Qt::darkGray));
    m_saveButton->setEnabled(false);
}

AccountWidget::AccountWidget(int& _currentAccounts, QStringList _accountDetails, Encrypter* _encrypter)
    : m_currentAccounts(_currentAccounts), m_encrypter(_encrypter)
{
    createWidgets();
    createLayouts();
    createConnections();
    setFixedHeight(120);

    m_accountID = QUuid::fromString(_accountDetails[0]);
    m_aliasLE->setText(_accountDetails[1]);
    m_usernameLE->setText(_accountDetails[2]);
    m_passwordLE->setText(m_encrypter->decrypt(_accountDetails[2], _accountDetails[3]));
    m_launchCheckBox->setChecked(_accountDetails[4].toInt());

    if (m_launchCheckBox->isChecked())
    {
        m_gamesComboBox->setCurrentIndex(_accountDetails[5].toInt());
    }

    m_saveButton->setPalette(QPalette(Qt::darkGray));
    m_saveButton->setText(tr("Saved!"));
    m_saveButton->setEnabled(false);
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

    m_launchCheckBox = new QCheckBox(tr("Auto Launch Game"));
    m_gamesComboBox = new QComboBox();
    m_gamesComboBox->setPalette(QPalette(Qt::darkGray));
    m_gamesComboBox->setInsertPolicy(QComboBox::InsertAfterCurrent);
    m_gamesComboBox->setEnabled(false);
    populateComboBox();

    m_batchProcess = new QProcess();
    m_batchProcess->setWorkingDirectory("../accounts");
}

void AccountWidget::createLayouts()
{
    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->addWidget(m_aliasLabel, 0, 0, 1, 1);
    mainLayout->addWidget(m_aliasLE, 1, 0, 1, 1);
    mainLayout->addWidget(m_usernameLabel, 0, 1, 1, 1);
    mainLayout->addWidget(m_usernameLE, 1, 1, 1, 1);
    mainLayout->addWidget(m_launchCheckBox, 2, 1, 1, 1);
    mainLayout->addWidget(m_passwordLabel, 0, 2, 1, 1);
    mainLayout->addWidget(m_passwordLE, 1, 2, 1, 1);
    mainLayout->addWidget(m_gamesComboBox, 2, 2, 1, 1);

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
    connect(m_aliasLE, SIGNAL(textChanged(QString)), this, SLOT(detailsEdited()));
    connect(m_usernameLE, SIGNAL(textChanged(QString)), this, SLOT(detailsEdited()));
    connect(m_passwordLE, SIGNAL(textChanged(QString)), this, SLOT(detailsEdited()));

    connect(m_loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
    connect(m_saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));

    connect(m_launchCheckBox, SIGNAL(stateChanged(int)), this, SLOT(launchCheckBoxChanged()));
    connect(m_gamesComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(detailsEdited()));

    connect(m_batchProcess, SIGNAL(finished(int)), this, SLOT(deleteScript()));
}

void AccountWidget::populateComboBox()
{
    QMapIterator<QString, QString> iter(m_gameLogos);
    iter.toBack();
    while (iter.hasPrevious())
    {
        iter.previous();
        m_gamesComboBox->insertItem(0, QIcon(":images/game_icons/" + iter.value()), iter.key());
    }
    m_gamesComboBox->setCurrentIndex(0);
}

void AccountWidget::loginButtonClicked()
{
    // Write launch script
    QString filePath = "../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".bat";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out << 
    "wmic process where name='steam.exe' delete\n"
    "start \"\" \"C:/Program Files (x86)/Steam/Steam.exe\" -login " << m_usernameLE->text() << " " << m_passwordLE->text();

    if (m_launchCheckBox->isChecked())
    {
        int launchID = m_gameIDs[m_gamesComboBox->currentText()];
        out << " -applaunch " << launchID;
    }

    // Run script
    m_batchProcess->start("cmd.exe", {QString("/C"), QString(m_accountID.toString(QUuid::WithoutBraces) + ".bat")});
}

void AccountWidget::saveButtonClicked()
{
    m_saveButton->setPalette(QPalette(Qt::darkGray));
    m_saveButton->setText(tr("Saved!"));
    m_saveButton->setEnabled(false);

    // Create file
    QFile file("../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    // Write saved details
    QTextStream out(&file);
    out << m_aliasLE->text() << "\n" << m_usernameLE->text() << "\n"
        << m_encrypter->encrypt(m_usernameLE->text(), m_passwordLE->text())
        << "\n" << m_launchCheckBox->isChecked();

    if (m_launchCheckBox->isChecked())
    {
        out << "\n" << m_gamesComboBox->currentIndex();
    }
}

void AccountWidget::deleteButtonClicked()
{
    // Delete saved details
    if (QFile::exists("../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".txt"))
    {
        QFile::remove("../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".txt");
    }

    m_currentAccounts--;
    delete this;
}

void AccountWidget::detailsEdited()
{
    // Un-fade save button
    m_saveButton->setText(tr("Save"));

    if (m_aliasLE->text().length() > 0 && m_usernameLE->text().length() > 0 && m_passwordLE->text().length() > 0)
    {
        m_saveButton->setPalette(QPalette(QColor(45, 45, 45)));
        m_saveButton->setEnabled(true);
    }
    else
    {
        m_saveButton->setPalette(QPalette(Qt::darkGray));
        m_saveButton->setEnabled(false);
    }
}

void AccountWidget::launchCheckBoxChanged()
{
    // Fade games combo box
    if (m_launchCheckBox->isChecked())
    {
        m_gamesComboBox->setPalette(QPalette(QColor(45, 45, 45)));
        m_gamesComboBox->setEnabled(true);
    }
    else
    {
        m_gamesComboBox->setPalette(QPalette(Qt::darkGray));
        m_gamesComboBox->setEnabled(false);
    }
    detailsEdited();
}

void AccountWidget::deleteScript()
{
    // Delete launch script
    if (QFile::exists("../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".bat"))
    {
        QFile::remove("../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".bat");
    }
}
