#ifndef ACCOUNTWIDGET_H_
#define ACCOUNTWIDGET_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

class AccountWidget : public QGroupBox
{
    Q_OBJECT
public:
    AccountWidget();

public slots:
    void loginButtonClicked();
    void deleteButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    QLabel* m_usernameLabel;
    QLabel* m_passwordLabel;

    QLineEdit* m_usernameLE;
    QLineEdit* m_passwordLE;

    QPushButton* m_loginButton;
    QPushButton* m_deleteButton;
};

#endif  // _ACCOUNTWIDGET_H_