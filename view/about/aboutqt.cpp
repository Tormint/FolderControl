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

//About Qt Interface
//
////This file serves as the implementation file of the GUI for the 'About Qt'
////dialog of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Window'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#include "aboutqt.h"

//Constructor.
AboutQt::AboutQt(QObject *parent) : Window(parent)
{
    return;
}

//Initializes the objects that will be used in the view.
//Extends the functions of the base class implementations.
void AboutQt::createObjects()
{
    Window::createObjects();

    pLogo = new QPixmap("://img/qtlogo.png");

    lLogo = new QLabel();

    lCreatorT = new QLabel("<b><u>IDE Used:</u></b>");
    lCreator = new QLabel("Qt Creator 7.0.0 [Qt 6.2.3 (Revision 638b93591b)]");
    lVersionT = new QLabel("<b><u>Compiled Using:</u></b>");
    lVersion = new QLabel("Qt C++ 6.3.0");
    lCompiler = new QLabel("MinGW-64 11.2.0");
    lCopyright = new QLabel("<b><i>Copyright 2008-2022 The Qt Company Ltd. All rights reserved.</i></b>");
    lUrl = new QLabel("<a href=https://www.qt.io/>www.qt.io</a>");

    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void AboutQt::configureObjects()
{
    Window::configureObjects();

    Window::setIcon("://img/qtlogo.png");

    dWindow->setWindowTitle("About Qt");

    lUrl->setOpenExternalLinks(true);
    lUrl->setTextInteractionFlags(Qt::TextBrowserInteraction);

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void AboutQt::placeObjects()
{
    Window::placeObjects();

    if (!pLogo->isNull())
    {
        pLogo->scaled(QSize(80, 80), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        lLogo->setPixmap(*pLogo);
        glMainLayout->addWidget(lLogo, 0, 0, 3, 3);
    }

    glMainLayout->addWidget(lCreatorT, 0, 3, 1, 1, Qt::AlignLeft);
    glMainLayout->addWidget(lCreator, 0, 4, 1, 2, Qt::AlignRight);
    glMainLayout->addWidget(lVersionT, 1, 3, 1, 1, Qt::AlignLeft);
    glMainLayout->addWidget(lVersion, 1, 4, 1, 2, Qt::AlignRight);
    glMainLayout->addWidget(lCompiler, 2, 4, 1, 2, Qt::AlignRight);
    glMainLayout->addWidget(lCopyright, 3, 0, 1, 6, Qt::AlignCenter);
    glMainLayout->addWidget(lUrl, 4, 0, 1, 6, Qt::AlignCenter);

    return;
}

//void AboutQt::connectObjects()
//{
//    Window::connectObjects();
//
//    return;
//}
//
//void AboutQt::disconnectObjects()
//{
//    Window::disconnectObjects();
//
//    return;
//}

//Destructor.
AboutQt::~AboutQt()
{
    return;
}
