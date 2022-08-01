#ifndef ABOUTWIDGET_H_
#define ABOUTWIDGET_H_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

class AboutWidget : public QGroupBox
{
    Q_OBJECT
public:
    AboutWidget();

private:
    void createWidgets();
    void createLayouts();

    QLabel* m_welcomeLabel;
    QLabel* m_descriptionLabel;
    QLabel* m_DNTitleLabel;
    QLabel* m_DNDescriptionLabel;
    QLabel* m_contactLabel;
    QLabel* m_linkOne;
};

#endif   // _ABOUTWIDGET_H_