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

#include "../window.h"

#include <QObject>
#include <QLabel>
#include <QPixmap>

class AboutQt : public Window
{
    Q_OBJECT

public:

    AboutQt(QObject *parent = NULL);
    ~AboutQt();

protected:

    void createObjects();
    void configureObjects();
    void placeObjects();

private:

    QLabel *lCreatorT,
           *lCreator,
           *lCopyrightT,
           *lCopyright,
           *lVersionT,
           *lVersion,
           *lCompiler,
           *lUrlT,
           *lUrl,
           *lLogo;

    QPixmap *pLogo;

};

#endif // ABOUTQT_H
