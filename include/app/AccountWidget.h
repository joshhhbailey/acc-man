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

class AccountWidget : public QGroupBox
{
    Q_OBJECT
public:
    AccountWidget(int& _currentAccounts);
    AccountWidget(int& _currentAccounts, QStringList _accountDetails);

    void populateComboBox();

public slots:
    void loginButtonClicked();
    void saveButtonClicked();
    void deleteButtonClicked();
    void detailsEdited();
    void launchCheckBoxChanged();
    void deleteScript();

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

    QCheckBox* m_launchCheckBox;
    QComboBox* m_gamesComboBox;

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

    QMap<QString, QString> m_gameLogos = {{"Apex Legends", "1172470_icon.jpg"},
                                        {"Counter-Strike: Global Offensive", "730_icon.jpg"},
                                        {"Dota 2", "570_icon.jpg"},
                                        {"Grand Theft Auto V", "271590_icon.jpg"},
                                        {"PUBG: BATTLEGROUNDS", "578080_icon.jpg"},
                                        {"Rust", "252490_icon.jpg"},
                                        {"Team Fortress 2", "440_icon.jpg"}
                                       };
};

#endif  // _ACCOUNTWIDGET_H_