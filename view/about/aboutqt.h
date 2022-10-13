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
////This file serves as the definition file of the GUI for the 'About Qt' dialog
////of the program 'FolderControl'.
////
////The GUI controls all aspects related to the view and inherits from the base
////class 'Window'. It overrides virtual functions only and extends non-virtual
////functions.
////
////This file is a work in progress.

#ifndef ABOUTQT_H
#define ABOUTQT_H

//Base Class:

#include "../window.h"

//Qt Libs:

#include <QObject>
#include <QPixmap>
#include <QLabel>

//Dialog containing infromation about Qt Framework.
class AboutQt : public Window
{
    Q_OBJECT

public:

    //Constructor.
    AboutQt(QObject *parent = NULL);

    //Destructor.
    ~AboutQt();

protected:

    //Initializes the objects that will be used in the view.
    //Extends the functions of the base class implementations.
    void createObjects();

    //Configures the objects that will be used in the view.
    //Extends the functions of the base class implementations.
    void configureObjects();

    //Places the view objects in their perspective layouts and sets the layouts.
    //Extends the functions of the base class implementations.
    void placeObjects();

private:

    //View Objects:

    QPixmap *pLogo;

    QLabel *lLogo,
           *lCreatorT,
           *lCreator,
           *lVersionT,
           *lVersion,
           *lCompiler,
           *lCopyright,
           *lUrl;

};

#endif // ABOUTQT_H
