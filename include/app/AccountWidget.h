#ifndef ACCOUNTWIDGET_H_
#define ACCOUNTWIDGET_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtCore/QUuid>

class AccountWidget : public QGroupBox
{
    Q_OBJECT
public:
    AccountWidget(int& _currentAccounts);

public slots:
    void loginButtonClicked();
    void saveButtonClicked();
    void deleteButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    QLabel* m_aliasLabel;
    QLineEdit* m_aliasLE;

    QLabel* m_usernameLabel;
    QLineEdit* m_usernameLE;

    QLabel* m_passwordLabel;
    QLineEdit* m_passwordLE;

    QWidget* m_buttonsWidget;
    QPushButton* m_loginButton;
    QPushButton* m_saveButton;
    QPushButton* m_deleteButton;


    QUuid m_accountID = QUuid::createUuid();
    int& m_currentAccounts;
};

#endif  // _ACCOUNTWIDGET_H_