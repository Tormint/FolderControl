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
////This file serves as the definition file of the GUI for the 'About' dialog
////of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Window'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef ABOUT_H
#define ABOUT_H

#include "../window.h"

#include <QObject>

class About : public Window
{
    Q_OBJECT

public:

    About(QObject *parent = NULL);
    ~About();

protected:

    void createObjects();
    void configureObjects();
    void placeObjects();
    //void connectObjects();
    //void disconnectObjects();
};

#endif // ABOUT_H
