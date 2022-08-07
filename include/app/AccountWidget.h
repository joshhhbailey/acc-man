#ifndef ACCOUNTWIDGET_H_
#define ACCOUNTWIDGET_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtCore/QUuid>
#include <QtCore/QMap>
#include <QtCore/QProcess>

#include "Encrypter.h"

class AccountWidget : public QGroupBox
{
    Q_OBJECT
public:
    AccountWidget(int& _currentAccounts, Encrypter* _encrypter);
    AccountWidget(int& _currentAccounts, QStringList _accountDetails, Encrypter* _encrypter);

    void populateComboBox();

public slots:
    void loginButtonClicked();
    void saveButtonClicked();
    void deleteButtonClicked();
    void detailsEdited();
    void launchCheckBoxChanged();
    void passwordCheckBoxChanged();
    void deleteScript();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    Encrypter* m_encrypter;

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

    QCheckBox* m_launchCheckBox;
    QComboBox* m_gamesComboBox;
    QCheckBox* m_passwordCheckBox;

    QUuid m_accountID;
    int& m_currentAccounts;

    QProcess* m_batchProcess;

    QMap<QString, int> m_gameIDs = {{"Apex Legends", 1172470},
                                    {"Counter-Strike: Global Offensive", 730},
                                    {"Dota 2", 570},
                                    {"Grand Theft Auto V", 271590},
                                    {"PUBG: BATTLEGROUNDS", 578080},
                                    {"Rust", 252490},
                                    {"Team Fortress 2", 440}
                                   };

    QMap<QString, QString> m_gameLogos = {{"Apex Legends", "1172470_icon.png"},
                                          {"Counter-Strike: Global Offensive", "730_icon.png"},
                                          {"Dota 2", "570_icon.png"},
                                          {"Grand Theft Auto V", "271590_icon.png"},
                                          {"PUBG: BATTLEGROUNDS", "578080_icon.png"},
                                          {"Rust", "252490_icon.png"},
                                          {"Team Fortress 2", "440_icon.png"}
                                         };
};

#endif  // _ACCOUNTWIDGET_H_