#include <QtWidgets/QFormLayout>

#include "AboutWidget.h"

AboutWidget::AboutWidget()
{
    setWindowTitle("About");
    createWidgets();
    createLayouts();

    setFixedSize(400, 350);
}

void AboutWidget::createWidgets()
{
    m_welcomeLabel = new QLabel();
    m_welcomeLabel->setText("<b>Welcome to AccountManager v1.0.0!</b>");
    m_welcomeLabel->setAlignment(Qt::AlignCenter);

    m_descriptionLabel = new QLabel();
    m_descriptionLabel->setText("This tool has been developed with the intention of providing users\n"
                                "with the ability to switch accounts, across multiple platforms,\n"
                                "seamlessly. No typing required, just switch accounts at the\n"
                                "click of a button!\n");
    m_descriptionLabel->setAlignment(Qt::AlignCenter);
    
    m_DNTitleLabel = new QLabel();
    m_DNTitleLabel->setText("<b>Developer Notes:</b>");
    m_DNTitleLabel->setAlignment(Qt::AlignCenter);

    m_DNDescriptionLabel = new QLabel();
    m_DNDescriptionLabel->setText("AccountManager is both, free to use and distribute. However,\n"
                                  "please bear in mind that this piece of software is very much\n"
                                  "a work-in-progress. Feel free to reach out with any feature\n"
                                  "requests and/or bug reports to the email address below. Also note,\n"
                                  "your account details are encrypted and saved locally inside of\n"
                                  "the 'accounts' directory, located at your install path. If this\n"
                                  "software has been installed to a default location such as 'Program Files'\n"
                                  "in order to save and load your account details, you will need to run\n"
                                  "this software with admin privileges.");
    m_DNDescriptionLabel->setAlignment(Qt::AlignCenter);

    m_contactLabel = new QLabel();
    m_contactLabel->setText("<b>Contact</b>");
    m_contactLabel->setAlignment(Qt::AlignCenter);

    m_linkOne = new QLabel();
    m_linkOne->setText("<a href=\"mailto:joshhhbailey@gmail.com\">joshhhbailey@gmail.com</a>");
    m_linkOne->setTextFormat(Qt::RichText);
    m_linkOne->setTextInteractionFlags(Qt::TextBrowserInteraction);
    m_linkOne->setOpenExternalLinks(true);
    m_linkOne->setAlignment(Qt::AlignCenter);
}

void AboutWidget::createLayouts()
{
    QFormLayout *mainLayout = new QFormLayout();
    mainLayout->addRow(m_welcomeLabel);
    mainLayout->addRow(m_descriptionLabel);
    mainLayout->addRow(m_DNTitleLabel);
    mainLayout->addRow(m_DNDescriptionLabel);
    mainLayout->addRow(m_contactLabel);
    mainLayout->addRow(m_linkOne);
    setLayout(mainLayout);
}