#include <QtWidgets/QGridLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include "AccountWidget.h"

AccountWidget::AccountWidget(int& _currentAccounts) : m_currentAccounts(_currentAccounts)
{
    m_accountID = QUuid::createUuid();
    createWidgets();
    createLayouts();
    createConnections();
    setFixedHeight(120);
}

AccountWidget::AccountWidget(int& _currentAccounts, QStringList _accountDetails) : m_currentAccounts(_currentAccounts)
{
    createWidgets();
    createLayouts();
    createConnections();
    setFixedHeight(120);

    m_accountID = QUuid::fromString(_accountDetails[0]);
    m_aliasLE->setText(_accountDetails[1]);
    m_usernameLE->setText(_accountDetails[2]);
    m_passwordLE->setText(_accountDetails[3]);
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
}

void AccountWidget::populateComboBox()
{
    QMapIterator<QString, int> iter(m_gameIDs);
    iter.toBack();
    while (iter.hasPrevious())
    {
        iter.previous();
        QString logo = m_gameLogos.value(iter.key());
        m_gamesComboBox->insertItem(0, QIcon("../../images/" + logo), iter.key());
    }
    m_gamesComboBox->setCurrentIndex(0);
}

void AccountWidget::loginButtonClicked()
{
    // Write launch script
    QFile file("../../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".bat");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out << "Stop-Process -Name \"Steam\"\n"
    "start \"\" \"C:\\Program Files (x86)\\Steam\\Steam.exe\" -login " << m_usernameLE->text() << " " << m_passwordLE->text();

    if (m_launchCheckBox->isChecked())
    {
        int launchID = m_gameIDs[m_gamesComboBox->currentText()];
        out << " -applaunch " << launchID;
    }

    // Run .bat
    // Delete .bat
}

void AccountWidget::saveButtonClicked()
{
    m_saveButton->setPalette(QPalette(Qt::darkGray));
    m_saveButton->setText(tr("Saved!"));
    m_saveButton->setEnabled(false);

    // Write saved details
    QFile file("../../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    out << m_aliasLE->text() << "\n" << m_usernameLE->text() << "\n" << m_passwordLE->text() << "\n" << m_launchCheckBox->isChecked();

    if (m_launchCheckBox->isChecked())
    {
        out << "\n" << m_gamesComboBox->currentIndex();
    }
}

void AccountWidget::deleteButtonClicked()
{
    // Delete saved details
    if (QFile::exists("../../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".txt"))
    {
        QFile::remove("../../accounts/" + m_accountID.toString(QUuid::WithoutBraces) + ".txt");
    }

    m_currentAccounts--;
    delete this;
}

void AccountWidget::detailsEdited()
{
    // Fade save button
    m_saveButton->setPalette(QPalette(QColor(45, 45, 45)));
    m_saveButton->setText(tr("Save"));
    m_saveButton->setEnabled(true);
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
