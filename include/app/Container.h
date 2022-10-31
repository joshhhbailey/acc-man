#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>

class Container : public QGroupBox
{
    Q_OBJECT
public:
    Container();

private:
    void createWidgets();
    void createLayouts();
    virtual void createConnections() = 0;

protected:
    QHBoxLayout* m_mainLayout;
    QScrollArea* m_scrollArea;
    QWidget* m_mainWidget;
    QVBoxLayout* m_secondaryLayout;
};

#endif  // _CONTAINER_H_
