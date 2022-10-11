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
