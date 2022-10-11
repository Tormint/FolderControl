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

AboutQt::AboutQt(QObject *parent) : Window(parent)
{
    return;
}

void AboutQt::createObjects()
{
    Window::createObjects();

    lCreatorT = new QLabel("<b><u>IDE Used:</u></b>");

    lCreator = new QLabel("Qt Creator 7.0.0 [Qt 6.2.3 (Revision 638b93591b)]");

    lCopyrightT = new QLabel("<b><u>Copyright:</u></b>");

    lCopyright = new QLabel("Copyright 2008-2022 The Qt Company Ltd. All rights reserved.");

    lVersionT = new QLabel("<b><u>Compiled Using:</u></b>");

    lVersion = new QLabel("Qt C++ 6.3.0");

    lCompiler = new QLabel("MinGW-64 11.2.0");

    lUrlT = new QLabel("<b><u>Website:</u></b>");

    lUrl = new QLabel("https://www.qt.io/");

    pLogo = new QPixmap();

    return;
}

void AboutQt::configureObjects()
{
    Window::configureObjects();

    dWindow->setWindowTitle("About Qt");

    return;
}

void AboutQt::placeObjects()
{
    Window::placeObjects();

    if (pLogo->load(":/img/logo.png"))
    {
        lLogo->setPixmap(*pLogo);
        glMainLayout->addWidget(lLogo, 0, 0, 4, 4);
    }

    glMainLayout->addWidget(lCreatorT, 0, 0, 1, 2, Qt::AlignLeft);

    glMainLayout->addWidget(lCreator, 0, 2, 1, 4, Qt::AlignRight);

    glMainLayout->addWidget(lVersionT, 1, 0, 1, 2, Qt::AlignLeft);

    glMainLayout->addWidget(lVersion, 1, 2, 1, 4, Qt::AlignRight);

    glMainLayout->addWidget(lCompiler, 2, 2, 1, 4, Qt::AlignRight);

    glMainLayout->addWidget(lCopyrightT, 3, 0, 1, 2, Qt::AlignLeft);

    glMainLayout->addWidget(lCopyright, 3, 2, 1, 4, Qt::AlignRight);

    glMainLayout->addWidget(lUrlT, 4, 0, 1, 3, Qt::AlignLeft);

    glMainLayout->addWidget(lUrl, 4, 2, 1, 4, Qt::AlignRight);

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

AboutQt::~AboutQt()
{
    return;
}
