/******************************************************************************
 *******************************  Folder Control  *****************************
 ******************************************************************************
 *                                                                            *
 * Designed and written by LN du Rand (TorMint, the tormented peppermint).    *
 *                                                                            *
 * The source code is released under GNU General Public License v3.0.         *
 *                                                                            *
 * GitHub URL: https://github.com/Tormint/FolderControl                       *
 * Paypal URL: https://www.paypal.com/donate/?hosted_button_id=WCRQBGFZ2W8PY  *
 *                                                                            *
 ******************************************************************************/

//About Interface
//
////This file serves as the implementation file of the GUI for the 'About'
////dialog of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Window'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#include "about.h"

//Qt Libs:

#include <QDesktopServices>

//Constructor.
About::About(QObject *parent) : Window(parent)
{
    return;
}

//Initializes the objects that will be used in the view.
//Extends the functions of the base class implementations.
void About::createObjects()
{
    Window::createObjects();

    lIntro = new QLabel("<b><u>FolderControl: Useful functions for managing large folder trees.</u></b>");
    lDeveloperT = new QLabel("<b>Developer:</b>");
    lDeveloper = new QLabel("LN du Rand (BSc Computing)");
    lLicenseT = new QLabel("<b>License:</b>");
    lLicense = new QLabel("The source code is released under GNU General Public License v3.0.");
    lGithubT = new QLabel("<b>Github:</b>");
    lGithub = new QLabel("<a href=\"https://github.com/Tormint/FolderControl/\">https://github.com/Tormint/FolderControl/</a>");
    lMessage = new QLabel("<b><i>Consider donating to the developer if this software helped you:</b></i>");
    lPaypalT = new QLabel("<b>PayPal:</b>");
    lPaypal = new QLabel("<a href=\"https://www.paypal.com/donate/?hosted_button_id=WCRQBGFZ2W8PY\">https://www.paypal.com/donate/?hosted_button_id=WCRQBGFZ2W8PY</a>");
    lDonate = new QLabel();
    lInfo = new QLabel();

    pDonate = new QPixmap("://img/donate_btn1.png");
    pInfo = new QPixmap("://img/paypal.png");

    pbDonate = new QPushButton();

    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void About::configureObjects()
{
    Window::configureObjects();

    dWindow->setWindowTitle("About");

    lGithub->setOpenExternalLinks(true);
    lGithub->setTextInteractionFlags(Qt::TextBrowserInteraction);

    lPaypal->setOpenExternalLinks(true);
    lPaypal->setTextInteractionFlags(Qt::TextBrowserInteraction);

    lDonate->setOpenExternalLinks(true);
    lDonate->setTextInteractionFlags(Qt::TextBrowserInteraction);

    if (pDonate->isNull())
    {
        pbDonate->setText("Donate!");
    }
    else
    {
        pbDonate->setIcon(pDonate->scaled(QSize(150, 150), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        pbDonate->setIconSize(QSize(150, 75));
        pbDonate->setFlat(true);
    }

    pbDonate->setCursor(Qt::PointingHandCursor);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void About::placeObjects()
{
    Window::placeObjects();

    glMainLayout->addWidget(lIntro, 0, 0, 1, 2, Qt::AlignCenter);

    glMainLayout->addWidget(lDeveloperT, 1, 0, 1, 1, Qt::AlignLeft);
    glMainLayout->addWidget(lDeveloper, 1, 1, 1, 1, Qt::AlignRight);

    glMainLayout->addWidget(lLicenseT, 2, 0, 1, 1, Qt::AlignLeft);
    glMainLayout->addWidget(lLicense, 2, 1, 1, 1, Qt::AlignRight);

    glMainLayout->addWidget(lGithubT, 3, 0, 1, 1, Qt::AlignLeft);
    glMainLayout->addWidget(lGithub, 3, 1, 1, 1, Qt::AlignRight);

    glMainLayout->addWidget(lMessage, 4, 0, 1, 2, Qt::AlignCenter);

    glMainLayout->addWidget(lPaypalT, 5, 0, 1, 1, Qt::AlignLeft);
    glMainLayout->addWidget(lPaypal, 5, 1, 1, 1, Qt::AlignRight);

    glMainLayout->addWidget(pbDonate, 6, 0, 1, 2, Qt::AlignCenter);

    if (!pInfo->isNull())
    {
        lInfo->setPixmap(pInfo->scaled(QSize(150, 450), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    glMainLayout->addWidget(lInfo, 7, 0, 1, 2, Qt::AlignCenter);

    return;
}

//Connects the objects to their functional and managing code sources.
//Extends the functions of the base class implementations.
void About::connectObjects()
{
    Window::connectObjects();

    QObject::connect(pbDonate, SIGNAL(clicked(bool)), this, SLOT(linkPaypal()));

    return;
}

//Disconnects objects from their functional and managing code sources.
//Extends the functions of the base class implementations.
void About::disconnectObjects()
{
    Window::disconnectObjects();

    QObject::disconnect(pbDonate, SIGNAL(clicked(bool)), this, SLOT(linkPaypal()));

    return;
}

//Opens Paypal link in browser.
void About::linkPaypal()
{
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/donate/?hosted_button_id=WCRQBGFZ2W8PY"));

    return;
}

//Destructor.
About::~About()
{
    return;
}
