#ifndef PLATFORMCONTAINER_H_
#define PLATFORMCONTAINER_H_

#include <QtWidgets/QGroupBox>

#include "PlatformWidget.h"

class PlatformContainer : public QGroupBox
{
    Q_OBJECT
public:
    PlatformContainer();

private:
    void createWidgets();
    void createLayouts();

    PlatformWidget *m_platformWidget;
};

#endif  // _PLATFORMCONTAINER_H_