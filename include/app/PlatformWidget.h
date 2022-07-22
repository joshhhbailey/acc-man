#ifndef PLATFORMWIDGET_H_
#define PLATFORMWIDGET_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

class PlatformWidget : public QGroupBox
{
    Q_OBJECT
public:
    PlatformWidget();

public slots:
    void newButtonClicked();
    void deleteButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    void createConnections();

    QLabel* m_platformLabel;

    QPushButton* m_newButton;
    QPushButton* m_deleteButton;
};

#endif  // _PLATFORMWIDGET_H_