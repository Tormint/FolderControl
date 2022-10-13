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

    return;
}

//Configures the objects that will be used in the view.
//Extends the functions of the base class implementations.
void About::configureObjects()
{
    Window::configureObjects();

    dWindow->setWindowTitle("About");

    return;
}

//Places the view objects in their perspective layouts and sets the layouts.
//Extends the functions of the base class implementations.
void About::placeObjects()
{
    Window::placeObjects();

    return;
}

//void About::connectObjects()
//{
//    Window::connectObjects();
//
//    return;
//}
//
//void About::disconnectObjects()
//{
//    Window::disconnectObjects();
//
//    return;
//}

//Destructor.
About::~About()
{
    return;
}
