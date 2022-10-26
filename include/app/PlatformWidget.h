#ifndef PLATFORMWIDGET_H_
#define PLATFORMWIDGET_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtCore/QMap>

class PlatformWidget : public QGroupBox
{
    Q_OBJECT
public:
    PlatformWidget(QMap<QString, QString>& _platformLogos, QString _platformName);

public slots:
    void mainButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    QPushButton* m_mainButton;

    QMap<QString, QString> &m_platformLogos;
    QString m_platformName;
};

#endif  // _PLATFORMWIDGET_H_