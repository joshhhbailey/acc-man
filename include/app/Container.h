#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>

class Container : public QGroupBox
{
    Q_OBJECT
public:
    Container();

public slots:
    virtual void createButtonClicked();

private:
    void createWidgets();
    void createLayouts();
    virtual void createConnections();

protected:
    QVBoxLayout* m_mainLayout;
    QScrollArea* m_scrollArea;
    QWidget* m_mainWidget;
    QVBoxLayout* m_secondaryLayout;
    QPushButton* m_createButton;
};

#endif  // _CONTAINER_H_
